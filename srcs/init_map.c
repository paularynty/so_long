/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 20:47:10 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t  count_rows(char **grid)
{
    size_t  y;

    y = 0;
    while (grid[y])
        y++;
    return (y);
}

char    *read_map(char *map)
{
    char    *line;
    char    *temp;
    char    *joined_line;
    int     map_fd;

    map_fd = open(map, O_RDONLY);
    if (map_fd < 0)
    {
        close(map_fd);
        print_error("Failed to open map, verify that map file exists");
        exit(1);
    }
    joined_line = ft_calloc(1, sizeof(char *));
    if (!joined_line)
        return (NULL);
    line = get_next_line(map_fd);
    while (line != NULL)
    {
        temp = joined_line;
        joined_line = ft_strjoin(joined_line, line);
        free(temp);
        free(line);
        if (!joined_line)
            print_error("Memory allocation failed");
        line = get_next_line(map_fd);
    }
    close(map_fd);
    return (joined_line);
}

t_game  *init_game_struct(char **grid)
{
    t_game  *game;

    game = malloc(sizeof(t_game));
	// game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        free_game(game);
        print_error("Memory allocation failed");
    }
    game->map = grid;
    game->map_width = ft_strlen(grid[0]);
    game->map_height = count_rows(grid);
    game->collectables = count_collectables(game);
    game->player_x = player_position(game, 'x');
    game->player_y = player_position(game, 'y');
    game->exit_x = exit_position(game, 'x');
    game->exit_y = exit_position(game, 'y');
    game->steps = 0;
    game->won = 0;
    return (game);
}

t_game *init_map(char *map)
{
	char	*map_as_str;
	char	**map_as_array;
	t_game	*game;

    map_as_str = read_map(map);
	if (check_empty_lines(map_as_str) || check_map_content(map_as_str))
    {
        free(map_as_str);
        return (0);
    }
	map_as_array = ft_split(map_as_str, '\n');
	if (check_map_shape(map_as_array))
    {
        free(map_as_str);
        free_map(map_as_array, count_rows(map_as_array));
        return (0);
    }
	game = init_game_struct(map_as_array);
	if (check_walls(game))
    {
        free(map_as_str);
        free_game(game);
        return (0);
    }
	flood_fill(game);
	free(map_as_str);
	return (game);
}
