/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:01 by prynty            #+#    #+#             */
/*   Updated: 2024/08/25 18:25:49 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t  player_position(t_game *game, char c)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == 'P')
            {
                if (c == 'x')
                    return (x);
                else
                    return (y);
            }
            x++;
        }
        y++;
    }
    return (0);
}

static char **create_temp_map(t_game *game)
{
    size_t  i;
    char    **temp_map;

    temp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
    if (!temp_map)
        return (NULL);
    i = 0;
    while (i < game->map_height)
    {
        temp_map[i] = ft_strdup(game->map[i]);
        if (!temp_map[i])
        {
            while (i > 0)
            {
                free(temp_map[i - 1]);
                i--;
            }
            free(temp_map);
            return (NULL);
        }
        i++;
    }
    temp_map[game->map_height] = NULL;
    return (temp_map);
}

static int	flood_fill(t_game *game, char **temp_map, t_position position)
{
	static int	collectables = 0;
	static int	exit_found = 0;

	if (temp_map[position.y][position.x] == '1')
		return (0);
	else if (temp_map[position.y][position.x] == 'C')
		collectables++;
	else if (temp_map[position.y][position.x] == 'E')
	{
		exit_found = 1;
		return (0);
	}
	temp_map[position.y][position.x] = '1';
	flood_fill(game, temp_map, (t_position){position.x + 1, position.y});
	flood_fill(game, temp_map, (t_position){position.x - 1, position.y});
	flood_fill(game, temp_map, (t_position){position.x, position.y + 1});
	flood_fill(game, temp_map, (t_position){position.x, position.y - 1});
	if (collectables == game->collectables && exit_found)
		return (1);
	return (0);
}

int	validate_path(t_game *game, t_position position)
{
    size_t	i;
	int		result;
	char	**temp;

	temp = create_temp_map(game);
	if (!temp)
		print_error("Memory allocation failed");
	result = flood_fill(game, temp, position);
	i = 0;
	while (i < game->map_height)
		free(temp[i++]);
	free(temp);
	return (result);
}