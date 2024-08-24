/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 17:02:50 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *){0};
	if (check_args(argc, argv) == -1)
		return (FAILURE);
	game = init_map(argv[1]);
	if (!game)
		return (FAILURE);
	if (!init_game(game))
		return (FAILURE);
	// mlx_key_hook(game->mlx);
	// mlx_close_hook;
	ft_printf(GREEN"✨🥝🥭🍓🐉 ~~ Welcome to Baby Dragon's Lunchtime! ~~ 🐉🍓🥭🥝✨\n\n"RESET);
	// string_to_screen(game);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	// mlx_terminate(game->mlx);
		//check elements PCE01;
		//count_tile_size;
		//load_images;
		//parse_map;
		//init_game(game);
		//mlx_key_hook;
		//mlx_loop;
	end_game(game, game->mlx);
	return (0);
}
