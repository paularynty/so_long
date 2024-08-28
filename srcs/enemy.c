#include "../includes/so_long.h"

void	animate_enemy(t_game *game)
{
	size_t  i;

	i = 0;
	while (i < game->enemies)
	{
		if (game->enemy1->instances[i].enabled == true)
		{
			game->enemy1->instances[i].enabled = true;
			game->enemy2->instances[i].enabled = false;
			game->enemy3->instances[i].enabled = false;
		}
		else if (game->enemy2->instances[i].enabled == true)
		{
			game->enemy1->instances[i].enabled = false;
			game->enemy2->instances[i].enabled = true;
			game->enemy3->instances[i].enabled = false;
		}
		else
		{
			game->enemy1->instances[i].enabled = false;
			game->enemy2->instances[i].enabled = false;
			game->enemy3->instances[i].enabled = true;
		}
		i++;
	}
}