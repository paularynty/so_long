/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:39 by prynty            #+#    #+#             */
/*   Updated: 2024/09/04 18:50:21 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
    if (!map[i])
    {
		print_error("Empty map");
        return (1);
    }
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
        {
			print_error("Map contains empty lines");
            return (1);
        }
		i++;
	}
    return (0);
}

int check_map_shape(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
        {
			print_error("Map is not rectangular");
            return (1);
        }
		i++;
	}
    return (0);
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

int    check_map_content(char *map)
{
    size_t     i;
    size_t     player;
    size_t     collectables;
    size_t     exit;

	i = 0;
    player = 0;
   	collectables = 0;
	exit = 0;
	while (map[i] != '\0')
	{
        if (!(ft_strchr("PCE01\n", map[i])))
        {
            print_error("Map contains invalid characters");
            return (1);
        }            
        if (map[i] == 'P' && player != 0)
        {
            print_error("Verify that map contains only one player");
            return (1);
        }
        if (map[i] == 'E' && exit != 0)
        {
            print_error("Verify that map contains only one exit");
            return (1);
        }
        if (map[i] == 'P')
            player++;
        if (map[i] == 'C')
            collectables++;
        if (map[i] == 'E')
            exit++;
        i++;
    }
	if (player != 1 || exit != 1 || collectables < 1)
    {
        print_error("Verify player/collectable/exit values on map");
        return (1);
    }
    return (0);
}

int check_walls(t_game *game, char **map)
{
	size_t  i;
	
	i = 0;
    while (i < game->map_width)
    {
        if (game->map[0][i] != '1')
        {
            print_error("The map is not surrounded by walls (top row)");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < game->map_width)
    {
        if (game->map[game->map_height - 1][i] != '1')
        {
            print_error("The map is not surrounded by walls (bottom row)");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1')
        {
            print_error("The map is not surrounded by walls (left column)");
            return (1);
        }
        if (game->map[i][game->map_width - 1] != '1')
        {
            print_error("The map is not surrounded by walls (right column)");
            return (1);
        }
        i++;
    }
    return (0);
}
