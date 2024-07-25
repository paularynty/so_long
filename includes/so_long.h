/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:11:22 by prynty            #+#    #+#             */
/*   Updated: 2024/07/24 14:21:04 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_game
{
    void    *mlx_ptr;
    void    *window_ptr;
    int     collectables;
    int     size;
}   t_game;

void    check_args(int argc, char **argv);
int     print_error(char *message, t_game *game);
void    init_map(t_game *game, char *argv);
void    init_game(t_game *game);


#endif
