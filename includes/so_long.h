/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/08/27 15:31:09 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define PINK "\e[1m\e[38;5;205m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

# define TILESIZE 32

# define SCREEN_WIDTH 3200
# define SCREEN_HEIGHT 1800

# define SUCCESS 0
# define FAILURE -1

# define IMG_PLAYER "textures/player.png"
// # define IMG_COLL "textures/strawberry.png"
# define IMG_FRUIT1 "textures/kiwi.png"
# define IMG_FRUIT2 "textures/orange.png"
# define IMG_FRUIT3 "textures/strawberry.png"
# define IMG_FLOOR "textures/floor.png"
# define IMG_WALL "textures/wall.png"
# define IMG_EXIT "textures/exit.png"

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct  s_images
{
    mlx_image_t *player;
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
    
    char        *file;

    void        *mlx_ptr;
    void        *window_ptr;
    
    int         map_width;
    int         map_height;
    char        **map;

    mlx_t       *mlx;

    t_images    images;

    int         player_x;
    int         player_y;
    int         player_dir;

    int         exit_x;
    int         exit_y;

    int         player;
    int         exit;
    int         collectables;

    int         steps;
    int         score;
    int         won;
}   t_game;

//check_args.c
int         check_args(int argc, char **argv);

//check_map.c
int         check_empty_lines(char *map);
int         check_map_shape(char **grid);
int         check_map_content(char *map);
int         check_walls(t_game *game);
size_t      count_rows(char **grid);
size_t	    count_collectables(t_game *game);

//init_map.c
char        *read_map(char *map);
t_game      *init_game_struct(char **grid);
t_game      *init_map(char *map);

//validate_path.c
size_t      player_position(t_game *game, char c);
int         validate_path(t_game *game, t_position position);

//error_handling.c
void        clean_game(t_game *game);
void        free_game(t_game *game);
void        free_map(char **map, size_t height);
void        print_error(char *message);

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
#endif
