/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:38 by prynty            #+#    #+#             */
/*   Updated: 2024/08/28 20:41:04 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	animate_enemy(t_game *game)
// {
// 	size_t  i;

// 	i = 0;
// 	while (i < game->enemies)
// 	{
// 		if (game->enemy1->instances[i].enabled == true)
// 		{
// 			game->enemy1->instances[i].enabled = true;
// 			game->enemy2->instances[i].enabled = false;
// 			game->enemy3->instances[i].enabled = false;
// 		}
// 		else if (game->enemy2->instances[i].enabled == true)
// 		{
// 			game->enemy1->instances[i].enabled = false;
// 			game->enemy2->instances[i].enabled = true;
// 			game->enemy3->instances[i].enabled = false;
// 		}
// 		else
// 		{
// 			game->enemy1->instances[i].enabled = false;
// 			game->enemy2->instances[i].enabled = false;
// 			game->enemy3->instances[i].enabled = true;
// 		}
// 		i++;
// 	}
// }

static void	check_status(const t_game *game)
{
	int	i;

	i = 0;
	while (i < game->images.enemy->count)
	{
		if (game->player_x * TILESIZE
			== (size_t)game->images.enemy->instances[i].x
			&& game->player_y * TILESIZE
			== (size_t)game->images.enemy->instances[i].y)
		{
			mlx_close_window(game->mlx);
			ft_printf("Oh no! You ran into an enemy. Try again?");
		}
		i++;
	}
}

static void	move_all(const t_game *game, int i)
{
	t_var			var;

	var.x = &game->images.enemy->instances[i].x;
	var.y = &game->images.enemy->instances[i].y;
	var.ran_x = (rand() % 3 - 1) * 64;
	var.ran_y = (rand() % 3 - 1) * 64;
	var.index_x = *var.x + var.ran_x;
	var.index_y = *var.y + var.ran_y;
	if (var.index_x != 0)
		var.index_x /= TILESIZE;
	if (var.index_y != 0)
		var.index_y /= TILESIZE;
	if (game->map[var.index_y][var.index_x] != '1'
		&& game->map[var.index_y][var.index_x] != 'E')
	{
			*var.x += var.ran_x;
			*var.y += var.ran_y;
	}
}

void	enemy_patrol(void *temp)
{
	const t_game	*game = temp;
	int				count;
	static int		i;

	count = 0;
	check_status(game);
	if (i++ < EMOVE)
		return ;
	while (count < game->images.enemy->count)
	{
		move_all (game, count);
		count++;
	}
	i = 0;
}
