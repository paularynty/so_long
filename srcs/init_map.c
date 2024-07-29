/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:31:02 by prynty            #+#    #+#             */
/*   Updated: 2024/07/29 16:05:01 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int check_map_variables(char *argv, int pce[], int width)
// {
//     t_game  *game;
//     int     exit;
//     int     player;
//     int     collectables;
    
//     if (player != 1)
//         print_error("Map should contain one player");
//     if (exit != 1)
//         print_error("Map should contain one exit");
//     if (collectables == 0)
//         print_error("Map should contain at least one collectible");
// }

// int check_map_content(int map_fd, int size[])
// {
//     t_game  *game;
//     char    *line;

//     line = get_next_line(map_fd);
//     if (line == NULL)
//         print_error("Empty map");
//     size[0] = 0;
//     while (line[size[0]] != '\n' && line[size[0]] != '\0')
//         size[0]++;
//     size[1] = 0;
//     while (line != 0)
//     {
//         if (!check_map_variables)
//         {
//             free(line);
//             return (0);
//         }
//         size[1]++;
//         free(line);
//         line = get_next_line(map_fd);
//     }
// }

// int is_valid_map(char *argv, int size[])
// {
//     t_game  *game;
//     int     map_fd;
//     int     collectables;

//     collectables = check_map_content(map_fd, size);
//     close(map_fd);
//     if (!collectables)
//         return (0);
//     return (collectables);
// }

// char    *read_map(char *map)
// {
//     t_game  *game;
//     char    *line;
//     char    *line_joined;
//     int     fd;

//     fd = open(map, O_RDONLY);
//     if (fd < 0)
//             print_error("Failed to open map, use format: ./so_long [map].ber");
//     line_joined = ft_calloc(1, 1);
//     if (!line_joined)
//         return (NULL);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line)
//         {
//             line_joined = ft_strjoin(line_joined, line);
//             free(line);
//         }
//         else
//             print_error("Empty map");
//     }
//     close (fd);
//     return (line_joined);
// }

// t_game  *init_game(char *map)
// {
//     t_game  *game;
    
//     map = read_map(map);
//     return (game);   
// }

static void    check_map_variables(t_elements *elems, char c)
{
    if (c != '1' && c != 'C' && c != 'E' && c != 'P')
        print_error("Invalid characters in map");
    else if (c == 'P')
    {
        if (elems->player == 1)
            print_error("Only one player allowed in map");
        else
            elems->player = 1;
    }
    else if (c == 'C')
        elems->collectables = 1;
    else if (c == 'E')
        elems->exit = 1;
}

static void    find_player(t_game *game, int x, int y, char c)
{
    if (c == 'P')
    {
        game->player_x = x;
        game->player_y = y;
    }
    game->player_dir = 0;
}

static void    check_map_content(t_game *game)
{
    int         height;
    int         width;
    t_elements  elems;
    
    elems = (t_elements){0, 0, 0};
    height = 0;
    while (height < game->map_height)
    {
        width = 0;
        while (width < game->map_width)
        {
            if (height == 0 || width == 0 || height == game->map_height - 1
                || width == game->map_width - 1)
                {
                    if (game->map[width][height] != '1')
                        print_error("Map isn't surrounded by walls");
                }
            else
            {
                if (game->map[width][height] != '0')
                    check_map_variables(&elems, game->map[width][height]);
                find_player(game, width, height, game->map[width][height]);
            }
            width++;
        }
        height++;
    }
    if (elems.collectables == 0 || elems.exit == 0 || elems.player == 0)
        print_error("Missing player, collectables, or exit");
}

static int  check_map(t_game *game, char *map)
{
    int     map_fd;
    char    *line;
    int     width;
    int     height;

    map_fd = open(map, O_RDONLY);
    if (map_fd < 0)
            print_error("Failed to open map, use format: ./so_long [map].ber");
    line = get_next_line(map_fd);
    if (!line)
            print_error("Empty map");
    width = ft_strlen(line) - 1; // to ignore newline
    height = 0;
    while (line)
    {
        if (width != ft_strlen(line) - 1)
        {
            ft_printf("Line width is %d\n", width);
            print_error("Map is not rectangular");
            ft_printf("Line height is %d\n", height);
        }
        free(line);
        line = get_next_line(map_fd);
        height++;
    }
    close(map_fd);
    game->map_height = height;
    return (width);
}

void    read_map(t_game *game, char *map)
{
    char    *line;
    int     fd;
    int     i;

    game->map_width = check_map(game, map);
    fd = open(map, O_RDONLY);
    if (fd < 0)
            print_error("Failed to open map, use format: ./so_long [map].ber");
    game->map = (char **)malloc(sizeof(char *) * game->map_height);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        game->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    free(line);
    close(fd);
    game->steps = 0;
    check_map_content(game);
}
