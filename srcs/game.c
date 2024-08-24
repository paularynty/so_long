/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:00:50 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 17:11:24 by prynty           ###   ########.fr       */
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
        ft_printf("\nSuccess! Baby Dragon's belly is full!\n");
        ft_printf("You completed the game in");
        ft_printf(GREEN" %d "RESET, game->steps);
        ft_printf("moves. Can you do better? 🍓\n");
    }
    if (game->won == 0)
    {
        ft_printf("\nThe game ended. Why not try again?\n");
    }
    clean_game(game);
}