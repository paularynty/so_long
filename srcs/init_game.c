/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:29:55 by prynty            #+#    #+#             */
/*   Updated: 2024/08/15 12:53:46 by prynty           ###   ########.fr       */
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

    mlx = mlx_init(width, height, "Yay my game", false);
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
    game->images.collectible = load_image(game->mlx, IMG_COLL);
    game->images.wall = load_image(game->mlx, IMG_WALL);
    game->images.floor = load_image(game->mlx, IMG_FLOOR);
    game->images.exit = load_image(game->mlx, IMG_EXIT);
    if (!game->images.player || !game->images.collectible 
        || !game->images.wall || !game->images.floor || !game->images.exit)
        return (0);
    return (1);
}

int init_game(t_game *game)
{
    int     width;
    int     height;

    width = game->map_width * TILESIZE;
    if (width < 300)
        width = 300;
    height = game->map_height * TILESIZE;
    if (!init_mlx(game, width, height))
        return (0);
    if (!init_game_images(game))
    {
        mlx_terminate(game->mlx);
        return (0);
    }
    return (1);
}