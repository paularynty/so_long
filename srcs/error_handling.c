/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:57 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 11:12:10 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    clean_game(t_game *game)
{
    if (game->mlx)
    {
        if (game->images->wall)
            mlx_delete_image(game->mlx, game->images->wall);
        if (game->images->floor)
            mlx_delete_image(game->mlx, game->images->floor);
        if (game->images->collectable[0])
            mlx_delete_image(game->mlx, game->images->collectable[0]);
        if (game->images->collectable[1])
            mlx_delete_image(game->mlx, game->images->collectable[1]);
        if (game->images->collectable[2])
            mlx_delete_image(game->mlx, game->images->collectable[2]);
        if (game->images->exit)
            mlx_delete_image(game->mlx, game->images->exit);
        if (game->images->player)
            mlx_delete_image(game->mlx, game->images->player);
        mlx_terminate(game->mlx);
        game->mlx = NULL;
    }
    if (game->map->grid)
        free_array(&game->map->grid);
}

void free_game(t_game *game)
{
    size_t  i;

    i = 0;
    if (!game)
        return ;
    if (game->map->grid)
    {
        while (game->map->grid[i])
            free(game->map->grid[i++]);
        free(game->map->grid);
        game->map->grid = NULL;
    }
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

void    free_array(char ***array)
{
    int i;

    i = 0;
    if (*array)
    {
        while ((*array)[i] != NULL)
            free((*array)[i++]);
        free(*array);
        *array = NULL;
    }
}

void    print_error(char *message)
{
    ft_printf(PINK"Error\n"GREY"%s\n"RESET, message);
    exit(1);
}

void    map_error(t_map *map, char *message)
{
    if (map && map->grid)
        free_array(&map->grid);
    print_error(message);
}
