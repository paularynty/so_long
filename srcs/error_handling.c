/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:57 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 16:05:59 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int print_error(char *message)
{
    // t_game  *game;
    ft_printf(PINK"Error\n"GREY"%s\n"RESET, message);
    // free(game);
    exit(1);
}