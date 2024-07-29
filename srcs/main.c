/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 15:27:55 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(char *map)
{
	t_game	game;

	read_map(&game, map);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	///ft_memset(&game, 0, sizeof(t_game));
	check_args(argc, argv);
	init_game(argv[1]);
		//check_map_elements("01CPE");
		//count_tile_size;
		//load_images;
		//parse_map;
		//init_game(game);
		//mlx_key_hook;
		//mlx_loop;
		//clean_game;
	return (0);
}
