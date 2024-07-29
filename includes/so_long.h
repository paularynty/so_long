/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 17:30:27 by prynty           ###   ########.fr       */
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
    int     collectables;
    
    int     map_width;
    int     map_height;
    char    **map; //2D array

    int     steps;

    int     player_x;
    int     player_y;
    int     player_dir;
}   t_game;

typedef struct s_elements
{
    int     player;
    int     collectables;
    int     exit;
}   t_elements;


void    check_args(int argc, char **argv);
void    print_error(char *message);
char    *read_map(char *map);
t_game	*init_map(char *map);

//parse_map.c
void    check_empty_lines(char *map);
void    check_map_shape(char **grid);
size_t  count_rows(char **grid);
size_t	count_collectables(t_game *game);


#endif
