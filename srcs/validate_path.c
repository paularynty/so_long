/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:01 by prynty            #+#    #+#             */
/*   Updated: 2024/07/30 17:10:54 by prynty           ###   ########.fr       */
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
            if (game->map[x][y] == 'P')
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

size_t  exit_position(t_game *game, char c)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[x][y] == 'E')
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

int check_path(t_game *temp, size_t x, size_t y)
{
    if (temp->map[x][y] == '1')
        return (0);
    if (temp->map[x][y] == 'C')
        temp->collectables--;
    if (temp->map[x][y] == 'E')
    {
        temp->exit_x = 1;
        return (0);
    }
    temp->map[x][y] = '1';
    if (check_path(temp, x, y + 1))
        return (1);
    if (check_path(temp, x, y - 1))
        return (1);
    if (check_path(temp, x + 1, y))
        return (1);
    if (check_path(temp, x - 1, y))
        return (1);
    return (0);
}

void    validate_path(t_game *game)
{
    t_game  temp;
    size_t  i;

    temp.map_height = game->map_height;
    temp.map_width = game->map_width;
    temp.collectables = game->collectables;
    temp.player_x = game->player_x;
    temp.player_y = game->player_y;
    temp.exit_x = 0;
    temp.map = (char **)malloc(temp.map_height * sizeof(char *));
    if (!temp.map)
        print_error("Memory allocation failed");
    i = 0;
    while (i < temp.map_height)
    {
        temp.map[i] = ft_strdup(game->map[i]);
        i++;
    }
    check_path(&temp, temp.player_x, temp.player_y);
    if (!(temp.exit_x == 1 && temp.collectables == 0))
        print_error("No valid path available");
    free_map(temp.map, temp.map_height);    
}
