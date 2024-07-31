/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/07/31 11:15:56 by prynty           ###   ########.fr       */
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

size_t	count_collectables(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	collectables;

	y = 0;
	collectables = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				collectables++;
			}
			x++;
		}
		y++;
	}
	return (collectables);
}

char    *read_map(char *map)
{
    char    *line;
    char    *temp;
    char    *joined_line;
    int     map_fd;

    map_fd = open(map, O_RDONLY);
    if (map_fd < 0)
            exit_error("Failed to open map, use format: ./so_long [map].ber");
    joined_line = ft_calloc(1, 1);
    if (!joined_line)
        return (NULL);
    while (1)
    {
        line = get_next_line(map_fd);
        if (!line)
        {
            if (ft_strlen(joined_line) == 0)
                exit_error("Empty map");
            break ;
        }
        temp = joined_line;
        joined_line = ft_strjoin(joined_line, line);
        free(temp);
        free(line);
        if (!joined_line)
            return (NULL);
    }
    close(map_fd);
    return (joined_line);
}

t_game  *init_game_struct(char **grid)
{
    t_game  *game;

    game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        free_game(game);
        exit_error("Memory allocation failed");
    }
    game->map = grid;
    game->map_width = ft_strlen(grid[0]);
    game->map_height = count_rows(grid);
    game->collectables = count_collectables(game);
    // game->player_x = player_position(game, 'x');
    // game->player_y = player_position(game, 'y');
    // game->exit_x = exit_position(game, 'x');
    // game->exit_y = exit_position(game, 'y');
    game->steps = 0;
    game->won = 0;
    return (game);
}

t_game	*init_map(char *map)
{
	char	*map_as_str;
	char	**map_as_array;
	t_game	*game;

    map_as_str = read_map(map);
	check_empty_lines(map_as_str);
	check_map_content(map_as_str);
	map_as_array = ft_split(map_as_str, '\n');
	check_map_shape(map_as_array);
	game = init_game_struct(map_as_array);
	check_walls(game);
	// validate_path(game);
    //test;
	free(map_as_str);
	return (game);
}