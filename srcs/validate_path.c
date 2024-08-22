/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:33:01 by prynty            #+#    #+#             */
/*   Updated: 2024/08/22 18:41:54 by prynty           ###   ########.fr       */
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
            if (game->map[y][x] == 'E')
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

int check_path(t_game *temp, size_t y, size_t x)
{
    if (temp->map[y][x] == '1')
        return (0);
    if (temp->map[y][x] == '0')
        return (0);
    if (temp->map[y][x] == 'C')
        temp->collectables--;
    if (temp->map[y][x] == 'E')
    {
        temp->exit_x = 1;
        return (0);
    }
    temp->map[y][x] = '1';
    if (check_path(temp, y + 1, x))
        return (1);
    if (check_path(temp, y - 1, y))
        return (1);
    if (check_path(temp, y, x + 1))
        return (1);
    if (check_path(temp, y, x - 1))
        return (1);
    return (0);
}

void    flood_fill(t_game *game)
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
    check_path(&temp, temp.player_y, temp.player_x);
    if (!(temp.exit_x == 1 && temp.collectables == 0))
        print_error("No valid path available");
        //here should exit
    free_map(temp.map, temp.map_height);    
}
