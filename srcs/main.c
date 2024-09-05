/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 11:02:57 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t validate_file(char *file)
{
	int32_t	map_path_len;
	int32_t	map_file;
	
	if (!file[0])
	{
		print_error("Empty path");
		exit(1);
	}
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
	{
		close(map_file);
		print_error("Failed to open map");
		exit(1);
	}
	map_path_len = ft_strlen(file);
    if (map_path_len < 4 || ft_strncmp(&file[map_path_len - 4], ".ber", 4))
	{
		print_error("Invalid map path, use format: ./so_long [map].ber");
        return (FAILURE);
    }
	return (map_file);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	int32_t	map_file;

	// game = (t_game){0};
	if (check_args(argc, argv) == -1)
		return (FAILURE);
	map_file = validate_file(argv[1]);
	if (map_file == -1)
		return (FAILURE);
	ft_bzero(&map, sizeof(map));
	init_map(&map, map_file);
	ft_bzero(&game, sizeof(game));
	game.map = &map;
	init_game(&game);
	// if (!game)
	// 	return (FAILURE);
	// // if (init_game(game) == -1)
	// // 	return (FAILURE);
	start_game();
	string_to_screen(&game);
	mlx_key_hook(game.mlx, &key_hooks, &game);
	mlx_loop(game.mlx);
	end_game(&game, game.mlx);
	return (0);
}
