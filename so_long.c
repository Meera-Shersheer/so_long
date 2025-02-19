/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:15:49 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/19 22:30:37 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc , char **argv)
{
	char	**map;
	t_vars	game;
	t_sprites	sprites;
	
    if (argc != 2)
        exit_game(-1, NULL);
    check_extenstion(argv[1]);
	map = transform_into_matrix(read_map(argv[1]));
	if (map == NULL)
		exit_game(-1,NULL);
	check_Invalid_map(map);
	check_Invalid_path(map);
	game.mlx = mlx_init();
   	if (!game.mlx) 
   		exit_game(6, map);
	game.win_hight = ft_strlen_d(map) * 80;
	game.win_width = ft_strlen(*map) * 80;
	game.win = mlx_new_window(game.mlx,game.win_hight, game.win_width, "so_long");
	if (!game.win)
		exit_game(7, map);
	//render_game(map, &game);	
	load_image(&game, map, &sprites);
	fill_background(&game,sprites.background, map);
	draw_map(&game, &sprites, map);
	mlx_key_hook(game.win, hooks, &game);
	//mlx_loop_hook(game.mlx, int (*func)(), void *param);
	mlx_loop(game.mlx);
}

int hooks(int keycode, t_vars *game)
{

    printf("Key pressed: %d\n", keycode);
    if (keycode == XK_Escape)
    {
		//mlx_destroy_image(game->mlx,);
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
	return(0);
}










	// for (int i = 0;map[i]; i++)
	// {
	// 	printf("\"%s\"\n",map[i]);
	// }
void	render_game(char	**map, t_vars	*game)
{
	t_sprites	sprites;
	
	//(void)map;

	load_image(game, map, &sprites);

	fill_background(game,sprites.background, map);
	draw_map(game, &sprites, map);
}	


void	draw_map(t_vars *game, t_sprites *sprites, char **map)
{
	int i;
	size_t x;
	size_t y;
	t_image	*img;
	
	x = 0;
	y = 0;
	while (x < ft_strlen_d(map))
	{
		y = 0;
		while (y < ft_strlen(map[x]) )
		{
			if(map[x][y] == '1')
				img = sprites->wall;
			if(map[x][y] == '0')
				img = sprites->ground;
			if(map[x][y] == 'E')
				img = sprites->exit;
			if(map[x][y] == 'C')
				img = sprites->collectable;
			//else 
			//img = sprites->background;
			if(map[x][y] == 'P')
				img = sprites->player;
				
			i = mlx_put_image_to_window(game->mlx, game->win, img->scaled_image\
				, x * img->scaled_width, y * img->scaled_hight);
				if (i == 0)
				{
					//printf("HI2");
					exit(1);
				}
			y++;
		}	
		x++;
	}	
}