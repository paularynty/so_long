/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:13:19 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 11:35:40 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int draw_collectables(t_game *game, size_t y, size_t x)
{
    mlx_image_to_window(game->mlx, game->images.collectable, x * PIXELS, y * PIXELS);
    if (mlx_image_to_window < 0)
    {
        print_error("Failed to put collectable image to window");
        return (-1);
    }
    return (1);
}

static int draw_walls(t_game *game, size_t y, size_t x)
{
    mlx_image_to_window(game->mlx, game->images.wall, x * PIXELS, y * PIXELS);
    if (mlx_image_to_window < 0)
    {
        print_error("Failed to put wall image to window");
        return (-1);
    }
    return (1);
}

static int draw_player(t_game *game, size_t y, size_t x)
{
    mlx_image_to_window(game->mlx, game->images.player, x * PIXELS, y * PIXELS);
    if (mlx_image_to_window < 0)
    {
        print_error("Failed to put player image to window");
        return (-1);
    }
    return (1);
}

static int draw_exit(t_game *game, size_t y, size_t x)
{
    mlx_image_to_window(game->mlx, game->images.exit, x * PIXELS, y * PIXELS);
    if (mlx_image_to_window < 0)
    {
        print_error("Failed to put exit image to window");
        return (-1);
    }
    return (1);
}

int render_map(t_game *game)
{
    size_t  x;
    size_t  y;

    x = 0;
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                draw_walls(game, y, x);
            else if (game->map[y][x] == 'P')
                draw_player(game, y, x);
            else if (game->map[y][x] == 'C')
                draw_collectables(game, y, x);
            else if (game->map[y][x] == 'E')
                draw_exit(game, y, x);
            x++;
        }
        y++;
    }
    return (1);
}
