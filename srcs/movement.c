/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:34:09 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 12:48:45 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void move_player(int x, int y, t_game *game)
{
    if (game->map[y][x] == '1')
        return ;
    ft_printf("Steps: %d\n", game->steps);
}

void    key_hooks(mlx_key_data_t keydata, void *param)
{
    t_game  *game;
    int     x;
    int     y;

    game = (t_game *)param;
    x = game->player_x;
    y = game->player_y;
    //if (game->game_over)
        // return ;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        move_player(x, y - 1, game);
    else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
        move_player(x, y + 1, game);
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        move_player(x - 1, y, game);
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        move_player(x + 1, y, game);
}