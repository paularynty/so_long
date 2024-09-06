/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:11 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 16:57:27 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	validate_file(char *file)
{
	int	map_path_len;
	int	map_file;

	if (!file[0])
	{
		print_error("Empty path");
		exit(1);
	}
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
	{
		print_error("Failed to open map, verify that map file exists");
		exit(1);
	}
	map_path_len = ft_strlen(file);
	if (map_path_len < 4 || ft_strncmp(&file[map_path_len - 4], ".ber", 4))
	{
		print_error("Invalid map path, use format ./so_long_bonus [map].ber");
		return (-1);
	}
	return (map_file);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		map_file;

	if (argc != 2)
	{
		print_error("Usage: ./so_long_bonus [map].ber");
		return (-1);
	}
	game = (t_game *){0};
	map_file = validate_file(argv[1]);
	game = init_map(argv[1], map_file);
	if (!game)
		return (-1);
	if (init_game(game) == -1)
	{
		free_game(game);
		return (-1);
	}
	start_game();
	string_to_screen(game);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	end_game(game, game->mlx);
	return (0);
}
