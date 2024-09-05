/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 10:39:21 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static size_t  count_rows(char **map)
{
    size_t  y;

    y = 0;
    while (map[y])
        y++;
    return (y);
}

static void init_game_struct(t_game *game, char **map)
{
    // t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        free_game(game);
        map_error(NULL, "Memory allocation failed");
    }
    // game->map = map;
    // game->map_width = ft_strlen(map[0]);
    // game->map_height = count_rows(map);
    game->collectables = count_collectables(game, game->map);
    // game->player_x = player_position(game, 'x');
    // game->player_y = player_position(game, 'y');
    game->steps = 0;
    game->won = 0;
    game->score = 0;
    game->images.collectable_screen = 0;
    game->images.move_counter = 0;
    // return (game);
}

static void    check_map(t_map *map)
{
    int32_t     rows;
    int32_t     col;
    t_position  player_start;

	check_map_shape(map, map->grid);
    init_game_struct(game, game->map);
    check_walls(map, map->grid);
    map->player_x = player_position(map, 'x');
    map->player_y = player_position(map, 'y');
    player_start = (t_position){map->player_x, map->player_y};
	if (!validate_path(map, player_start))
        map_error(map, "No valid path available");
    // {
    //     free_game(game);
    //     print_error("No valid path available");
    //     return ;
    // }
	// return (game);
}

int init_map(t_map *map, int32_t map_fd)
{
    char        map_as_str[MAX_BYTE];
    int32_t     bytes_read;
    
    ft_bzero(map_as_str, MAX_BYTE);
    bytes_read = read(map_fd, map_as_str, MAX_BYTE);
    close(map_fd);
    if (bytes_read == -1)
        print_error("Failed to read map");
    else if (bytes_read == 0)
        print_error("Empty map");
    else if (bytes_read > MAX_ROW * (MAX_COL + 1))
        print_error("Map is too large");
    if (check_empty_lines(map_as_str) || check_map_content(map_as_str))
        return (FAILURE);
    map->grid = ft_split(map_as_str, '\n');
    if (!map->grid)
        map_error(map, "Split failed");
    // //check for NULL if split fails & free, as if you would with malloc
    map->map_width = ft_strlen(map->grid[0]);
    map->map_height = count_rows(map->grid);
    check_map(map);
    return (SUCCESS);
}
