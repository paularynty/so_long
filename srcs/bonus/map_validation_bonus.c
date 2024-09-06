/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:39 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 17:51:56 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_empty_lines(char *map)
{
	size_t	i;

	i = 0;
	if (!map[i])
	{
		print_error("Empty map");
		free(map);
		return (1);
	}
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n')
			|| (map[i] == '\n' && (map[i + 1] == '\0')))
		{
			print_error("Map contains empty lines");
			free(map);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map_shape(char *map, char **grid)
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
			free(map);
			free_map(grid, count_rows(grid));
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls_x(t_game *game, char *map)
{
	size_t	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
		{
			print_error("Map is not surrounded by walls (top row)");
			free(map);
			free_game(game);
			return (1);
		}
		if (game->map[game->map_height - 1][i] != '1')
		{
			print_error("Map is not surrounded by walls (bottom row)");
			free(map);
			free_game(game);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls_y(t_game *game, char *map)
{
	size_t	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1')
		{
			print_error("Map is not surrounded by walls (left column)");
			free(map);
			free_game(game);
			return (1);
		}
		if (game->map[i][game->map_width - 1] != '1')
		{
			print_error("Map is not surrounded by walls (right column)");
			free(map);
			free_game(game);
			return (1);
		}
		i++;
	}
	return (0);
}
