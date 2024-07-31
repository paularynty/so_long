/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:57 by prynty            #+#    #+#             */
/*   Updated: 2024/07/31 10:33:38 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
        i++;
    }
    free(map);
}

void    exit_error(char *message)
{   
    ft_printf(PINK"Error\n"GREY"%s\n"RESET, message);
    exit(1);
}
