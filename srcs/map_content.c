/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:29:53 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 21:10:42 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
            free(map);
            return (1);
        }            
        if (map[i] == 'P' && player != 0)
        {
            print_error("Verify that map contains only one player");
            free(map);
            return (1);
        }
        if (map[i] == 'E' && exit != 0)
        {
            print_error("Verify that map contains only one exit");
            free(map);
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
        free(map);
        return (1);
    }
    return (0);
}
