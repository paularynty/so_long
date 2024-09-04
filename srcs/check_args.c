/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:21:11 by prynty            #+#    #+#             */
/*   Updated: 2024/09/04 18:08:14 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_args(int argc, char **argv)
{
    t_game  *game;
    size_t  map_path_len;
    
    if (argc < 2)
    {
        print_error("Missing map file, use format: ./so_long [map].ber");
        return (FAILURE);
    }
    else if (argc > 2)
    {
        print_error("Too many arguments, use format: ./so_long [map].ber");
        return (FAILURE);
    }
    // else
    // // {
    // //     map_path_len = ft_strlen(argv[1]);
    // //     if (map_path_len < 4 || ft_strncmp(&argv[1][map_path_len - 4], ".ber", 4))
    // //     {
    // //         print_error("Invalid map path, use format: ./so_long [map].ber");
    // //         return (FAILURE);
    // //     }
    // // }
    return (SUCCESS);
}

