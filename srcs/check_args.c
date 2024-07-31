/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:21:11 by prynty            #+#    #+#             */
/*   Updated: 2024/07/31 10:35:03 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args(int argc, char **argv)
{
    size_t     map_path_len;
    
    if (argc < 2)
        exit_error("Missing map file, use format: ./so_long [map].ber");
    else if (argc > 2)
        exit_error("Too many arguments, use format: ./so_long [map].ber");
    else
    {
        map_path_len = ft_strlen(argv[1]);
        if (!ft_strnstr(&argv[1][map_path_len - 4], ".ber", 4))
            exit_error("Invalid map path, use format: ./so_long [map].ber");
    }
}