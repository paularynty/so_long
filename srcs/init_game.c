/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:29:55 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 15:43:23 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t *load_image(mlx_t *mlx, const char *imgfile)
{
    mlx_texture_t   *texture;
    mlx_image_t     *image;
    
    image = NULL;
    texture = mlx_load_png(imgfile);
    if (!texture)
    {
        print_error("Failed to load texture");
        return (0);
    }
    image = mlx_texture_to_image(mlx, texture);
    if (!image)
    {
        print_error("Problem with texture to image");
        return (0);
    }
    mlx_delete_texture(texture);
    return (image);
}

int init_mlx(t_game *game, int width, int height)
{
    mlx_t   *mlx;

    mlx = mlx_init(width, height, "Yay my game", true);
    if (!mlx)
    {
        free_map(game->map, game->map_height);
        print_error("Failed to initialize MLX");
        return (0);
    }
    game->mlx = mlx;
    return (1);
}

int init_game_images(t_game *game)
{   
    game->images.player = load_image(game->mlx, IMG_PLAYER);
    game->images.collectable = load_image(game->mlx, IMG_COLL);
    game->images.wall = load_image(game->mlx, IMG_WALL);
    game->images.floor = load_image(game->mlx, IMG_FLOOR);
    game->images.exit = load_image(game->mlx, IMG_EXIT);
    if (!game->images.player || !game->images.collectable 
        || !game->images.wall || !game->images.floor || !game->images.exit)
        return (0);
    return (1);
}

int init_game(t_game *game)
{
    int     width;
    int     height;

    width = game->map_width * TILESIZE;
    height = game->map_height * TILESIZE;
    if (!init_mlx(game, width, height))
        return (0);
    mlx_set_setting(MLX_STRETCH_IMAGE, 1);
    if (!init_game_images(game))
    {
        mlx_terminate(game->mlx);
        return (0);
    }
    fill_background(game);
    render_map(game);
    return (1);
}

int fill_background(t_game *game)
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
            if (mlx_image_to_window(game->mlx, game->images.floor, x * TILESIZE, y * TILESIZE) < 0)
                {
                    print_error("Failed to put floor image to window");
                    return (FAILURE);
                }
                x++;
        }
        y++;
    }
    return (1);
}

int draw_images(t_game *game, size_t y, size_t x)
{
    if (game->map[y][x] == '1')
    {
        if (mlx_image_to_window(game->mlx, game->images.wall, x * TILESIZE, y * TILESIZE) < 0)
                {
                    print_error("Failed to put wall image to window");
                    return (FAILURE);
                }
    }
    if (game->map[y][x] == 'C')
    {
        if (mlx_image_to_window(game->mlx, game->images.collectable, x * TILESIZE, y * TILESIZE) < 0)
                {
                    print_error("Failed to put collectable image to window");
                    return (FAILURE);
                }
    }
    else if (game->map[y][x] == 'P')
    {
        if (mlx_image_to_window(game->mlx, game->images.player, x * TILESIZE, y * TILESIZE) < 0)
                {
                    print_error("Failed to put player image to window");
                    return (FAILURE);
                }
    }
    else if (game->map[y][x] == 'E')
    {
        if (mlx_image_to_window(game->mlx, game->images.exit, x * TILESIZE, y * TILESIZE) < 0)
                {
                    print_error("Failed to put exit image to window");
                    return (FAILURE);
                }
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
            draw_images(game, y, x);
            x++;
        }
        y++;
    }
    return (1);
}
