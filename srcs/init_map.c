/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/07/24 14:28:36 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map_variables(char *argv, int pce[], int width)
{
    t_game  *game;
    int     exit;
    int     player;
    int     collectables;
    
    if (player != 1)
        print_error("Map should contain one player", game);
    if (exit != 1)
        print_error("Map should contain one exit", game);
    if (collectibles == 0)
        print_error("Map should contain at least one collectible", game);
}

int check_map_content(int map_fd, int size[])
{
    t_game  *game;
    char    *line;

    line = get_next_line(map_fd);
    if (line == NULL)
        print_error("Empty map", game);
    size[0] = 0;
    while (line[size[0]] != '\n' && line[size[0]] != '\0')
        size[0]++;
    size[1] = 0;
    while (line != 0)
    {
        if (!check_map_variables)
        {
            free(line);
            return (0);
        }
        size[1]++;
        free(line);
        line = get_next_line(map_fd);
    }
}

int is_valid_map(char *argv, int size[])
{
    t_game  *game;
    int     map_fd;
    int     collectables;

    map_fd = open(argv, O_RDONLY);
    if (map_fd < 0)
        print_error("Failed to open map, use format: ./so_long [map].ber", game);
    collectables = check_map_content(map_fd, size);
    close(map_fd);
    if (!collectables)
        return (0);
    return (collectables);
}

void    init_map(t_game *game, char *argv)
{
    game = malloc(sizeof(t_game));
    if (game == NULL)
        return (NULL);
    game->collectables = is_valid_map(argv, game->size);
    if (game->collectables == 0)
    {
        free(game);
        return (0);
    }
        
}