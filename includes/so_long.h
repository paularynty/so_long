/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/09/05 09:28:35 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN "\033[1;32m"
# define PINK "\e[1m\e[38;5;205m"
# define GREY "\033[0;90m"
# define RESET "\033[0m"

# define TILESIZE 32
# define MAX_BYTE 8107
# define MAX_ROW 67
# define MAX_COL 120

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160

# define SUCCESS 0
# define FAILURE -1

# define IMG_ENEMY "textures/enemy.png"
# define IMG_EXIT "textures/basket.png"
# define IMG_FLOOR "textures/floor.png"
# define IMG_COLL1 "textures/kiwi.png"
# define IMG_COLL2 "textures/orange.png"
# define IMG_COLL3 "textures/strawberry.png"
# define IMG_PLAYER "textures/player.png"
# define IMG_WALL "textures/wall1.png"

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
    mlx_image_t *collectable[3];
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

    int         collectables;
    int         steps;
    int         score;
    int         won;
}   t_game;

//check_args.c
int         check_args(int argc, char **argv);

//check_map.c
int         check_empty_lines(char *map);
int         check_map_shape(t_game *game, char **map);
int         check_walls(t_game *game, char **map);
int         check_map_content(char *map);
// size_t      count_rows(char **grid);
size_t	    count_collectables(t_game *game);

//init_map.c
int         init_map(t_game *game, int32_t map_file);
// t_game      *init_game_struct(char **map);

//validate_path.c
size_t      player_position(t_game *game, char c);
int         validate_path(t_game *game, t_position position);

//error_handling.c
void        clean_game(t_game *game);
void        free_game(t_game *game);
void        free_map(char **map, size_t height);
void        free_array(char ***array);
void        print_error(char *message);
void        map_error(t_game *game, char *message);

//init_game.c
int         init_mlx(t_game *game, int width, int height);
int         init_game(t_game *game);
mlx_image_t *load_image(mlx_t *mlx, const char *imgfile);
int         draw_images(t_game *game, size_t y, size_t x);
int         render_map(t_game *game);

//game_text.c
void        start_game(void);
void        string_to_screen(t_game *game);
void        print_moves(t_game *game);
void        print_collectables(t_game *game);
void        end_game(t_game *game, mlx_t *mlx);

//movement.c
void        key_hooks(mlx_key_data_t keydata, void *param);

//enemy.c
// void	    animate_enemy(t_game *game);

#endif