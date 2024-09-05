/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 21:23:53 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN "\033[1;32m"
# define PINK "\e[1m\e[38;5;205m"
# define GREY "\033[0;90m"
# define RESET "\033[0m"

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160
# define PIXELS 32

# define SUCCESS 0
# define FAILURE -1

# define IMG_ENEMY "textures/enemy.png"
# define IMG_EXIT "textures/basket.png"
# define IMG_FLOOR "textures/floor.png"
# define IMG_COLLECTABLE "textures/strawberry.png"
# define IMG_PLAYER "textures/player.png"
# define IMG_WALL "textures/wall.png"

# include "../libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct  s_images
{
    mlx_image_t *player;
    mlx_image_t *enemy;
    mlx_image_t *fruit1;
    mlx_image_t *fruit2;
    mlx_image_t *fruit3;
    mlx_image_t *collectable;
    mlx_image_t *collectable_screen;
    mlx_image_t *wall;
    mlx_image_t *floor;
    mlx_image_t *exit;
    mlx_image_t *move_counter;
    mlx_image_t *moves;
}   t_images;

typedef struct  s_position
{
    int x;
    int y;
}   t_position;

typedef struct	s_game
{
    t_position  position;
    t_images    images;
    mlx_t       *mlx;
    char        **map;
    int         map_width;
    int         map_height;
    int         player_x;
    int         player_y;
    int         player;
    int         collectables;
    int         exit;
    int         steps;
    int         score;
    int         won;
}   t_game;

//error_handling.c
void        clean_game(t_game *game);
void        free_game(t_game *game);
void        free_map(char **map, size_t height);
void        print_error(char *message);

//map_validation.c
int         check_empty_lines(char *map);
// int         check_map_shape(char **grid);
int         check_map_shape(char *map, char **grid);
int         check_map_content(char *map);
int         check_walls_horizontal(t_game *game, char *map);
int         check_walls_vertical(t_game *game, char *map);
size_t	    count_collectables(t_game *game);

//map_init.c
size_t      count_rows(char **map);
t_game      *init_game_struct(char **grid);
t_game      *init_map(char *map, int32_t map_file);

//map_path.c
size_t      player_position(t_game *game, char c);
int	        validate_path(t_game *game, char **grid, char *map);
// int         validate_path(t_game *game, t_position position);

//game_init.c
int         init_mlx(t_game *game, int width, int height);
int         init_game(t_game *game);
mlx_image_t *load_image(mlx_t *mlx, const char *imgfile);

//game_images.c
int         render_map(t_game *game);

//game_movement.c
void        key_hooks(mlx_key_data_t keydata, void *param);

//game_control.c
void        start_game(void);
void        string_to_screen(t_game *game);
void        print_moves(t_game *game);
void        print_collectables(t_game *game);
void        end_game(t_game *game, mlx_t *mlx);

#endif