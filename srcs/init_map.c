/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 17:43:22 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char    *read_map(char *map)
{
    t_game  *game;
    char    *line;
    char    *line_joined;
    int     fd;

    fd = open(map, O_RDONLY);
    if (fd < 0)
            print_error("Failed to open map, use format: ./so_long [map].ber");
    line_joined = ft_calloc(1, 1);
    if (!line_joined)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line)
        {
            line_joined = ft_strjoin(line_joined, line);
            free(line);
        }
        else
            print_error("Empty map");
            break ;
    }
    close (fd);
    return (line_joined);
}

void    check_map_content(char *map)
{
    int player;
    int exit;
    int collectables;
    int i;

    player = 0;
	exit = 0;
	collectables = 0;
	i = 0;
	while (map[i++])
	{
		if (map[i] == 'P')
			player++;
        if (map[i] == 'C')
			collectables++;
		if (map[i] == 'E')
			exit++;
		if (!(ft_strchr("PCE01\n", map[i])))
        		print_error("Map contains invalid characters");
	}
	if (player != 1 || exit != 1 || collectables < 1)
		print_error("Invalid player/exit/collectable values (one/one/at least one)");
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
	// data = initialize_game_struct(map_as_array);
	// check_walls(data);
	// flood_fill(data);
	free (map_as_str);
	return (game);
}

t_game  *init_game(char **grid)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        print_error("Memory allocation failed");
    game->map_width = ft_strlen(grid[0]);
    game->map_height = count_rows(grid);
    game->map = grid;
    game->steps = 0;
    return (game);
}
