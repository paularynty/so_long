/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:29:55 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 11:12:55 by prynty           ###   ########.fr       */
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

    mlx = mlx_init(width, height, "Baby Dragon's Lunchtime", true);
    if (!mlx)
    {
        free_map(game->map->grid, game->map->map_height);
        print_error("Failed to initialize MLX");
        return (0);
    }
    game->mlx = mlx;
    return (1);
}

int init_game_images(t_game *game)
{ 
    game->images->enemy = load_image(game->mlx, IMG_ENEMY);
    game->images->exit = load_image(game->mlx, IMG_EXIT);
    game->images->collectable[0] = load_image(game->mlx, IMG_COLL1);
    game->images->collectable[1] = load_image(game->mlx, IMG_COLL2);
    game->images->collectable[2] = load_image(game->mlx, IMG_COLL3);
    game->images->floor = load_image(game->mlx, IMG_FLOOR);
    game->images->player = load_image(game->mlx, IMG_PLAYER);
    game->images->wall = load_image(game->mlx, IMG_WALL);
    if (!game->images->enemy || !game->images->player 
        || !game->images->collectable[0] || !game->images->collectable[1]
        || !game->images->collectable[2] || !game->images->wall 
        || !game->images->floor || !game->images->exit)
        return (FAILURE);
    return (SUCCESS);
}

static int render_background(t_game *game)
{
    size_t  x;
    size_t  y;
    
    x = 0;
    y = 0;
    while (y < game->map->map_height)
    {
        x = 0;
        while (x < game->map->map_width)
        {
            if (mlx_image_to_window(game->mlx, game->images->floor, x * TILESIZE, y * TILESIZE) < 0)
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

static void init_game_struct(t_game *game)
{
    // t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        free_game(game);
        map_error(NULL, "Memory allocation failed");
    }
    // game->map = map;
    // game->map_width = ft_strlen(map[0]);
    // game->map_height = count_rows(map);
    // game->collectables = count_collectables(game, game->map);
    // game->player_x = player_position(game, 'x');
    // game->player_y = player_position(game, 'y');
    game->steps = 0;
    game->won = 0;
    game->score = 0;
    game->images->collectable_screen = 0;
    game->images->move_counter = 0;
    // return (game);
}

int init_game(t_game *game)
{
    int     width;
    int     height;

    init_game_struct(game);
    width = game->map->map_width * TILESIZE;
    height = game->map->map_height * TILESIZE;
    if (!init_mlx(game, width, height))
        return (FAILURE);
    mlx_set_setting(MLX_STRETCH_IMAGE, 1);
    if (init_game_images(game) == -1)
    {
        mlx_terminate(game->mlx);
        return (FAILURE);
    }
    render_background(game);
    render_map(game);
    return (SUCCESS);
}

