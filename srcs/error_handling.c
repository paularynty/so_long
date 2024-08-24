/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:57 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 14:57:41 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    clean_game(t_game *game)
{
    size_t  i;

    if (game->mlx)
    {
        if (game->images.wall)
            mlx_delete_image(game->mlx, game->images.wall);
        if (game->images.floor)
            mlx_delete_image(game->mlx, game->images.floor);
        if (game->images.collectable)
            mlx_delete_image(game->mlx, game->images.collectable);
        if (game->images.exit)
            mlx_delete_image(game->mlx, game->images.exit);
        if (game->images.player)
            mlx_delete_image(game->mlx, game->images.player);
        mlx_terminate(game->mlx);
        game->mlx = NULL;
    }
    i = 0;
    if (game->map)
    {
        while (game->map[i])
            free(game->map[i++]);
        free(game->map);
        game->map = NULL;
    }
}

void free_game(t_game *game)
{
    size_t  i;

    i = 0;
    if (!game)
        return ;
    while (game->map[i] != NULL)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    free(game);
}

void    free_map(char **map, size_t height)
{
    size_t  i;

    i = 0;
    while (i < height)
    {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
}

void    print_error(char *message)
{
    ft_printf(PINK"Error\n"GREY"%s\n"RESET, message);
}
