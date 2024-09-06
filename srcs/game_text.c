/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:00:50 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 12:34:40 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	string_to_screen(t_game *game)
{
	char	*str;

	str = ft_itoa(game->collectables);
	game->images.moves = mlx_put_string(game->mlx, "Steps:", 24,
			game->map_height * PIXELS - 26);
	mlx_put_string(game->mlx, "Fruits:", 150,
		game->map_height * PIXELS - 26);
	mlx_put_string(game->mlx, "/", 260, game->map_height * PIXELS - 26);
	mlx_put_string(game->mlx, str, 278, game->map_height * PIXELS - 26);
	free(str);
}

void	print_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_delete_image(game->mlx, game->images.move_counter);
	game->images.move_counter = mlx_put_string(game->mlx, str, 96,
			game->map_height * PIXELS - 26);
	free(str);
}

void	print_collectables(t_game *game)
{
	char	*str;

	str = ft_itoa(game->score);
	mlx_delete_image(game->mlx, game->images.collectable_screen);
	game->images.collectable_screen = mlx_put_string(game->mlx, str, 232,
			game->map_height * PIXELS - 26);
	free(str);
}

void	start_game(void)
{
	ft_printf("\n✨🥝🥭🍓🐉🍓🥭✨🍓🥝🥭🐉🍓🥭✨🥝🥭🍓🐉🍓🥭✨\n");
	ft_printf("🍓                                        🐉\n");
	ft_printf(GREEN"🥭    Welcome to Lunchtime with Dragon!   🥝\n"RESET);
	ft_printf("🐉                                        ✨\n");
	ft_printf("🥝            Play as a dragon            🍓\n"RESET);
	ft_printf("✨           and collect fruits.          🥭\n"RESET);
	ft_printf("🥭           Easy enough, innit?          🥝\n"RESET);
	ft_printf("🍓                                        🐉\n");
	ft_printf("✨🥝🥭🍓🐉🍓🥭🥝✨🥝🥭🍓🐉🍓🥭🥝✨🍓🐉🍓🥭✨\n\n");
}

void	end_game(t_game *game, mlx_t *mlx)
{
	if (game->won == 1)
	{
		ft_printf("\nSuccessfully collected all fruits!\n");
		ft_printf("You completed the game in");
		ft_printf(GREEN" %d "RESET, game->steps);
		ft_printf("moves. Can you do better? 🍓\n\n");
	}
	if (game->won == 0)
		ft_printf("\nThe game ended. Why not try again?\n\n");
	clean_game(game);
}
