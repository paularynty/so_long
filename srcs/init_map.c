/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/09/04 11:28:33 by prynty           ###   ########.fr       */
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
    char        line[MAX_BYTE];
    char        *temp;
    char        *joined_line;
    int32_t     map_fd;
    int32_t     bytes_read;
    t_game      *game;

    ft_bzero(line, MAX_BYTE);
    bytes_read = read(map_fd, line, MAX_BYTE);
    close(map_fd);
    if (bytes_read == -1)
        print_error("Failed to read map");
    else if (bytes_read == 0)
        print_error("Empty map");
    else if (bytes_read > MAX_ROW * (MAX_COL + 1))
        print_error("Map is too large");
    game->map = ft_split(line, '\n');
    if (!game->map)
        print_error("Split failed");
    game->map_width = ft_strlen(grid[0]);
    game->map_height = count_rows(grid);
    
    
    // map_fd = open(map, O_RDONLY);
    // if (map_fd < 0)
    // {
    //     close(map_fd);
    //     print_error("Failed to open map, verify that map file exists");
    //     exit(1);
    // }
    // joined_line = ft_calloc(1, sizeof(char *));
    // if (!joined_line)
    //     return (NULL);
    // line = get_next_line(map_fd);
    // while (line != NULL)
    // {
    //     temp = joined_line;
    //     joined_line = ft_strjoin(joined_line, line);
    //     free(temp);
    //     free(line);
    //     if (!joined_line)
    //         print_error("Memory allocation failed");
    //     line = get_next_line(map_fd);
    // }
    // close(map_fd);
    // return (joined_line);
}

t_game  *init_game_struct(char **grid)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
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
    game->steps = 0;
    game->won = 0;
    game->score = 0;
    game->images.collectable_screen = 0;
    game->images.move_counter = 0;
    return (game);
}

t_game *init_map(char *map)
{
    t_game      *game;
	char	    *map_as_str;
	char	    **map_as_array;
    t_position  player_start;

    map_as_str = read_map(map);
	if (check_empty_lines(map_as_str) || check_map_content(map_as_str))
    {
        free(map_as_str);
        return (0);
    }
	map_as_array = ft_split(map_as_str, '\n');
    //check for NULL if split fails & free, as if you would with malloc
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
    player_start = (t_position){game->player_x, game->player_y};
	if (!validate_path(game, player_start))
    {
        print_error("No valid path available");
        free(map_as_str);
        free_game(game);
        return (0);
    }
	free(map_as_str);
	return (game);
}
