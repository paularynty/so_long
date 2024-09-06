/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/09/06 18:02:20 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define GREEN "\033[1;32m"
# define PINK "\e[1m\e[38;5;205m"
# define GREY "\e[0m\e[38;5;245m"
# define RESET "\033[0m"

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160
# define PIXELS 32

# define IMG_EXIT "textures/basket.png"
# define IMG_FLOOR "textures/floor.png"
# define IMG_COLLECTABLE "textures/strawberry.png"
# define IMG_PLAYER "textures/player.png"
# define IMG_WALL "textures/wall.png"

# include "MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_images
{
	mlx_image_t		*player;
	mlx_image_t		*enemy;
	mlx_image_t		*collectable;
	mlx_image_t		*collectable_screen;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
	mlx_image_t		*move_counter;
	mlx_image_t		*moves;
}	t_images;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	t_position	position;
	t_images	images;
	mlx_t		*mlx;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			player;
	int			collectables;
	int			exit;
	int			steps;
	int			score;
	int			won;
}	t_game;

//error_handling.c
void	clean_game(t_game *game);
void	free_game(t_game *game);
void	free_map(char **map, size_t height);
void	print_error(char *message);

//map_content.c
int		check_map_objects(t_game *game, char *map);

//map_validation.c
int		check_empty_lines(char *map);
int		check_map_shape(char *map, char **grid);
int		check_walls_x(t_game *game, char *map);
int		check_walls_y(t_game *game, char *map);

//map_init.c
size_t	count_rows(char **map);
t_game	*init_map(char *map, int map_file);

//map_path.c
size_t	player_position(t_game *game, char c);
int		validate_path(t_game *game, char **grid, char *map);

//game_init.c
int		init_game(t_game *game);

//game_images.c
int		render_map(t_game *game);

//game_movement.c
void	key_hooks(mlx_key_data_t data, void *param);

//game_control.c
void	start_game(void);
void	string_to_screen(t_game *game);
void	print_moves(t_game *game);
void	print_collectables(t_game *game);
void	end_game(t_game *game, mlx_t *mlx);

#endif
