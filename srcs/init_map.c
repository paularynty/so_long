/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 09:10:01 by prynty           ###   ########.fr       */
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
    // char        *temp;
    // char        *joined_line;
    
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

t_game  *init_game_struct(char **map)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        free_game(game);
        map_error(NULL, "Memory allocation failed");
    }
    game->map = map;
    game->map_width = ft_strlen(map[0]);
    game->map_height = count_rows(map);
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

static void    check_map(t_game *game)
{
    int32_t     rows;
    int32_t     col;
    t_position  player_start;

	check_map_shape(game, game->map);
	check_walls(game, game->map);
    game = init_game_struct(game->map);
    player_start = (t_position){game->player_x, game->player_y};
	if (!validate_path(game, player_start))
        map_error(game, "No valid path available");
    // {
    //     print_error("No valid path available");
    //     free_game(game);
    //     return ;
    // }
	// return (game);
}

int init_map(t_game *game, int32_t map_fd)
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
    game->map = ft_split(map_as_str, '\n');
    if (!game->map)
        map_error(game, "Split failed");
    // //check for NULL if split fails & free, as if you would with malloc
    game->map_width = ft_strlen(game->map[0]);
    game->map_height = count_rows(game->map);
    check_map(game);
    return (SUCCESS);
}
