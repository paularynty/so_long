/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 18:55:48 by prynty           ###   ########.fr       */
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
	if (init_game(game) == -1)
		return (FAILURE);
	start_game();
	string_to_screen(game);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	end_game(game, game->mlx);
	return (0);
}
