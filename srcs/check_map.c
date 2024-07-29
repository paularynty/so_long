/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:27 by prynty            #+#    #+#             */
/*   Updated: 2024/07/25 12:18:30 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    check_empty_line(char *map)
{
    size_t  i;
    
    i = 0;
    while (map[i])
    {
        if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
            print_error("Map contains empty lines");
        i++;
    }
}