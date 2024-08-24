/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:00:50 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 14:58:27 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void    string_to_screen(t_game *game)
// {
    
// }

void    end_game(t_game *game, mlx_t *mlx)
{
    if (game->won == 1)
    {
        ft_printf("You won!\n");
    }
    if (game->won == 0)
    {
        ft_printf("The game ended. Why not try again?\n");
    }
    clean_game(game);
    // mlx_close_window(mlx);
    // mlx_terminate(mlx);
}