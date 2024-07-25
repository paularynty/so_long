/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:43:04 by prynty            #+#    #+#             */
/*   Updated: 2024/07/23 17:09:41 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    init_game(t_game *game)
{
    game->mlx_ptr = mlx_init(300, 300, "SO_LONG", true);
    if (game->mlx_ptr == NULL)
    {
        free(game->mlx_ptr);
        print_error("Could not find mlx pointer", game);
    }
    game->window_ptr = mlx_new_window(); //have to find existing func for this
    if (game->window_ptr == NULL)
    {
        free(game->mlx_ptr);
        print_error("Could not create window", game);
    }
}
