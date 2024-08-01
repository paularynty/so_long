/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/08/01 12:54:22 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (check_args(argc, argv))
		return (1);
	game = init_map(argv[1]);
	if(!game)
		return (1);
		//check elements PCE01;
		//count_tile_size;
		//load_images;
		//parse_map;
		//init_game(game);
		//mlx_key_hook;
		//mlx_loop;
	free_game(game);
	return (0);
}
