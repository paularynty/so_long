/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:34:09 by prynty            #+#    #+#             */
/*   Updated: 2024/08/24 17:12:49 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void update_movement(t_game *game, int x, int y)
{
    game->map[game->player_y][game->player_x] = '0';
    game->map[y][x] = 'P';
    game->images.player->instances[0].x = x * TILESIZE;
    game->images.player->instances[0].y = y * TILESIZE;
}

static void collect_item(t_game *game, int x, int y)
{
    size_t  i;

    i = 0;
    game->score++;
    while (i < game->images.collectable->count)
    {
        if (game->images.collectable->instances[i].x == x * TILESIZE
            && game->images.collectable->instances[i].y == y * TILESIZE)
            {
                game->images.collectable->instances[i].enabled = false;
                break ;
            }
            i++;
    }
}

static int  validate_exit(t_game *game, int x, int y)
{
    if (game->map[y][x] == 'E')
    {
        if (game->score != game->collectables)
        {
            ft_printf("Collect all fruits before exiting the game 🍓\n");
            return (FAILURE);
        }
        else
        {
            game->won = 1;
            mlx_close_window(game->mlx);
        }
    }
    return (SUCCESS);
}

static void move_player(t_game *game, int x, int y)
{
    if (game->map[y][x] == '1')
        return ;
    if (game->map[y][x] == '0')
        update_movement(game, x, y);
    else if (game->map[y][x] == 'C')
    {
        update_movement(game, x, y);
        collect_item(game, x, y);
    }
    if (validate_exit(game, x, y) == -1)
        return ;
    game->player_x = x;
    game->player_y = y;
    game->steps++;
    ft_printf("🥝 Steps: %d\n", game->steps);
}

void    key_hooks(mlx_key_data_t keydata, void *param)
{
    t_game  *game;
    int     x;
    int     y;

    game = (t_game *)param;
    x = game->player_x;
    y = game->player_y;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        move_player(game, x, y - 1);
    else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
        move_player(game, x, y + 1);
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        move_player(game, x - 1, y);
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        move_player(game, x + 1, y);
}
