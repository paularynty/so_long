int	main(int argc, char **argv)
{
    t_game	*game;
    
    memset(&game, 0, sizeof(t_game));
    if (argc == 2)
    {
        is_valid_map;
        init_map;
        check_map_elements("01CPE");
        count_tile_size;
        load_images;
        parse_map;
        game_start;
        mlx_key_hook;
        mlx_loop;
        clean_game;
    }
    return (0);
}
