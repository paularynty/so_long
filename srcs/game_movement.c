/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:34:09 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 13:29:08 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_movement(t_game *game, int x, int y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->images.player->instances[0].x = x * PIXELS;
	game->images.player->instances[0].y = y * PIXELS;
}

static void	collect_item(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->collectables)
	{
		if ((game->images.collectable->instances[i].x == x * PIXELS)
			&& (game->images.collectable->instances[i].y
				== y * PIXELS))
		{
			game->images.collectable->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

static int	validate_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->score != game->collectables)
		{
			ft_printf("🧺 Collect all fruits first!\n");
			return (-1);
		}
		else
		{
			game->won = 1;
			mlx_close_window(game->mlx);
		}
	}
	return (0);
}

static void	move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == '0')
		update_movement(game, x, y);
	else if (game->map[y][x] == 'C')
	{
		update_movement(game, x, y);
		collect_item(game, x, y);
		game->score++;
		ft_printf("🍓 Collected a fruit!\n");
		print_collectables(game);
	}
	if (validate_exit(game, x, y) == -1)
		return ;
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	print_moves(game);
	ft_printf("🥝 Steps: %d\n", game->steps);
}

void	key_hooks(mlx_key_data_t data, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->player_x;
	y = game->player_y;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if ((data.key == MLX_KEY_UP && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_W && data.action == MLX_PRESS))
		move_player(game, x, y - 1);
	else if ((data.key == MLX_KEY_DOWN && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_S && data.action == MLX_PRESS))
		move_player(game, x, y + 1);
	else if ((data.key == MLX_KEY_LEFT && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_A && data.action == MLX_PRESS))
		move_player(game, x - 1, y);
	else if ((data.key == MLX_KEY_RIGHT && data.action == MLX_PRESS)
		|| (data.key == MLX_KEY_D && data.action == MLX_PRESS))
		move_player(game, x + 1, y);
}
