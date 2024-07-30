/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/07/30 16:57:35 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define PINK "\e[1m\e[38;5;205m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_game
{
    void    *mlx_ptr;
    void    *window_ptr;
    
    int     map_width;
    int     map_height;
    char    **map; //2D array

    int     player_x;
    int     player_y;
    int     player_dir;

    int     exit_x;
    int     exit_y;

    int     player;
    int     exit;
    int     collectables;

    int     steps;
    int     won;
}   t_game;

//check_args.c
void    check_args(int argc, char **argv);

//check_map.c
void    check_empty_lines(char *map);
void    check_map_shape(char **grid);
void    check_map_content(char *map);
void	check_walls(t_game *game);
size_t  count_rows(char **grid);
size_t	count_collectables(t_game *game);

//init_map.c
char    *read_map(char *map);
t_game  *init_game_struct(char **grid);
t_game	*init_map(char *map);

//validate_path.c
size_t  player_position(t_game *game, char c);
size_t  exit_position(t_game *game, char c);
void    validate_path(t_game *game);

//error_handling.c
void    free_game(t_game *game);
void    free_map(char **map, size_t height);
void    print_error(char *message);

#endif
