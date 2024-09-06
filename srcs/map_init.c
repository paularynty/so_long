/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 11:00:25 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t   count_rows(char **map)
{
    size_t  y;

    y = 0;
    while (map[y])
        y++;
    return (y);
}

static char *read_map(char *map, int32_t map_file)
{
    char    *line;
    char    *temp;
    char    *joined_line;

    joined_line = ft_calloc(1, sizeof(char *));
    if (!joined_line)
        return (NULL);
    line = get_next_line(map_file);
    while (line != NULL)
    {
        temp = joined_line;
        joined_line = ft_strjoin(joined_line, line);
        if (!joined_line)
        {
            free(joined_line);
            print_error("Memory allocation failed");
        }
        free(temp);
        free(line);
        line = get_next_line(map_file);
    }
    close(map_file);
    return (joined_line);
}

static t_game *init_variables(char **map)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        free_game(game);
        print_error("Memory allocation failed");
    }
    game->map = map;
    game->map_width = ft_strlen(map[0]);
    game->map_height = count_rows(map);
    game->player_x = player_position(game, 'x');
    game->player_y = player_position(game, 'y');
    game->steps = 0;
    game->won = 0;
    game->score = 0;
    game->player = 0;
    game->collectables = 0;
    game->exit = 0;
    game->images.collectable_screen = 0;
    game->images.move_counter = 0;
    return (game);
}

t_game    *init_map(char *map, int32_t map_file)
{
    t_game      *game;
	char	    *map_as_str;
	char	    **map_as_array;

    map_as_str = read_map(map, map_file);
	if (check_empty_lines(map_as_str))
        return (0);
	map_as_array = ft_split(map_as_str, '\n');
	if (check_map_shape(map_as_str, map_as_array))
        return (0);
	game = init_variables(map_as_array);
    if (check_map_objects(game, map_as_str))
    {
        free_game(game);
        return (0);
    }
	if (check_walls_vertical(game, map_as_str) || (check_walls_horizontal(game, map_as_str)))
        return (0);
	if (!validate_path(game, map_as_array, map_as_str))
    {
        free_game(game);
        return (0);
    }
	free(map_as_str);
	return (game);
}
