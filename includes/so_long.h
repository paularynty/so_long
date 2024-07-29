/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 15:25:21 by prynty           ###   ########.fr       */
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
int     print_error(char *message);
void    read_map(t_game *game, char *map);
void	init_game(char *map);
void    check_empty_line(char *map);

#endif
