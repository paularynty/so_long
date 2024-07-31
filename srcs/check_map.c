/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:39 by prynty            #+#    #+#             */
/*   Updated: 2024/07/31 10:50:02 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
    if (!map[i])
		exit_error("Empty map");
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
			exit_error("Map contains empty lines");
		i++;
	}
}

void check_map_shape(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			exit_error("Map is not rectangular");
		i++;
	}
}

void    check_map_content(char *map)
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
            exit_error("Map contains invalid characters");
        if (map[i] == 'P' && player != 0)
            exit_error("Verify that map contains only one player");
        if (map[i] == 'E' && exit != 0)
            exit_error("Verify that map contains only one exit");
        if (map[i] == 'P')
            player++;
        if (map[i] == 'C')
            collectables++;
        if (map[i] == 'E')
            exit++;
        i++;
    }
	if (collectables < 1) 
		exit_error("Verify that map contains at least one collectable");
}

void	check_walls(t_game *game)
{
	size_t i;
	
	i = 0;
    while (i < game->map_width)
    {
        if (game->map[0][i] != '1')
            exit_error("The map is not surrounded by walls (top row)");
        i++;
    }
    i = 0;
    while (i < game->map_width)
    {
        if (game->map[game->map_height - 1][i] != '1')
            exit_error("The map is not surrounded by walls (bottom row)");
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1')
            exit_error("The map is not surrounded by walls (left column)");
        if (game->map[i][game->map_width - 1] != '1')
            exit_error("The map is not surrounded by walls (right column)");
        i++;
    }
}
