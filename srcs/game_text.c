/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:00:50 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 11:13:54 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    string_to_screen(t_game *game)
{
    char    *str;

    game->images->moves = mlx_put_string(game->mlx, "Steps:", 24,
        game->map->map_height * TILESIZE - 26);
    mlx_image_to_window(game->mlx, game->images->collectable[0], 136,
        game->map->map_height * TILESIZE - 32);
    mlx_put_string(game->mlx, ":", 170, game->map->map_height * TILESIZE - 26);
    mlx_put_string(game->mlx, "/", 216, game->map->map_height * TILESIZE - 26);
    str = ft_itoa(game->map->collectables);
    mlx_put_string(game->mlx, str, 232, game->map->map_height * TILESIZE - 26);
    free(str);
}

void    print_moves(t_game *game)
{
    char    *str;

    str = ft_itoa(game->steps);
    mlx_delete_image(game->mlx, game->images->move_counter);
    game->images->move_counter = mlx_put_string(game->mlx, str, 100, game->map->map_height
        * TILESIZE - 26);
    free(str);
}

void    print_collectables(t_game *game)
{
    char    *str;

    str = ft_itoa(game->score);
    mlx_delete_image(game->mlx, game->images->collectable_screen);
    game->images->collectable_screen = mlx_put_string(game->mlx, str, 190,
        game->map->map_height * TILESIZE - 26);
    free(str);
}

void    start_game(void)
{
    ft_printf(GREEN"\n✨🥝🥭🍓🐉 ~~ Welcome to Baby Dragon's Lunchtime! ~~ 🐉🍓🥭🥝✨\n\n"RESET);
}

void    end_game(t_game *game, mlx_t *mlx)
{
    if (game->won == 1)
    {
        ft_printf("\nSuccessfully collected all fruits!\n");
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
