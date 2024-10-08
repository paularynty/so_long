/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:29:55 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 17:32:25 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static mlx_image_t	*load_image(mlx_t *mlx, const char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	image = NULL;
	texture = mlx_load_png(file);
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

static int	init_mlx(t_game *game, int width, int height)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, height, "Lunchtime with Dragon", true);
	if (!mlx)
	{
		free_map(game->map, game->map_height);
		print_error("Failed to initialize MLX");
		return (-1);
	}
	game->mlx = mlx;
	return (1);
}

static int	init_game_images(t_game *game)
{
	game->images.exit = load_image(game->mlx, IMG_EXIT);
	game->images.collectable = load_image(game->mlx, IMG_COLLECTABLE);
	game->images.floor = load_image(game->mlx, IMG_FLOOR);
	game->images.player = load_image(game->mlx, IMG_PLAYER);
	game->images.wall = load_image(game->mlx, IMG_WALL);
	if (!game->images.player || !game->images.collectable || !game->images.wall
		|| !game->images.floor || !game->images.exit)
		return (-1);
	return (0);
}

static int	render_background(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (mlx_image_to_window(game->mlx, game->images.floor,
					x * PIXELS, y * PIXELS) < 0)
			{
				print_error("Failed to put floor image to window");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	init_game(t_game *game)
{
	int	width;
	int	height;

	width = game->map_width * PIXELS;
	height = game->map_height * PIXELS;
	if (width > SCREEN_WIDTH || height > SCREEN_HEIGHT)
	{
		print_error("Map is too large, try with smaller map");
		return (-1);
	}
	if (init_mlx(game, width, height) == -1)
		return (-1);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (init_game_images(game) == -1)
	{
		mlx_terminate(game->mlx);
		return (-1);
	}
	render_background(game);
	render_map(game);
	return (0);
}
