/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:29:53 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 16:55:02 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	check_characters(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (!(ft_strchr("PCE01\n", map[i])))
		{
			print_error("Map contains invalid characters");
			free(map);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	count_objects(t_game *game, char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			game->player++;
		if (map[i] == 'C')
			game->collectables++;
		if (map[i] == 'E')
			game->exit++;
		i++;
	}
	return (0);
}

static int	verify_objects(char *map, int player,
		int collectables, int exit)
{
	if (player != 1 || collectables < 1 || exit != 1)
	{
		print_error("Verify player/collectable/exit values on map");
		free(map);
		return (1);
	}
	return (0);
}

int	check_map_objects(t_game *game, char *map)
{
	if (check_characters(map))
		return (1);
	if (count_objects(game, map))
		return (1);
	if (verify_objects(map, game->player, game->collectables, game->exit))
		return (1);
	return (0);
}
