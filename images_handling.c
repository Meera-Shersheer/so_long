/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:38:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/20 04:22:09 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_image( t_vars	*game , char **map,t_sprites *sprites)
{
	int dim;

	dim = 80;
	if(!game || !(game->mlx) || !sprites)
		exit_game(8, map);
	sprites_init(sprites ,map);
	if(!(sprites->door_player) || !(sprites->door_open))
		exit_game(8, map);	
	if(!(sprites->wall) || !(sprites->background) || !(sprites->ground))
		exit_game(8, map);
	if(!(sprites->collectable) || !(sprites->exit) || !(sprites->player))
		exit_game(8, map);
	load_xpm_image(game ,sprites->background,"./sprites/background01.xpm", dim);	
	load_xpm_image(game ,sprites->wall,"./sprites/wall.xpm", dim);
	load_xpm_image(game ,sprites->collectable,"./sprites/collectable1.xpm", dim);
	load_xpm_image(game ,sprites->ground,"./sprites/Grass.xpm", dim);	
	load_xpm_image(game ,sprites->exit,"./sprites/door/Doors_closed.xpm", dim);
	load_xpm_image(game ,sprites->player,"./sprites/player/player_front_3.xpm", dim);
	load_xpm_image(game ,sprites->door_open,"./sprites/door/Doors_open_2.xpm", dim);
	load_xpm_image(game ,sprites->door_player,"./sprites/door/door_player.xpm", dim);
	resize_image(game , sprites->background, dim, dim);
	resize_image(game ,sprites->collectable,dim,dim);
	resize_image(game ,sprites->exit,dim,dim);
	resize_image(game ,sprites->ground,dim,dim);
	resize_image(game ,sprites->player,dim,dim);
	resize_image(game ,sprites->wall,dim,dim);
	resize_image(game ,sprites->door_open,dim,dim);
	resize_image(game ,sprites->door_player,dim,dim);
}

void resize_image(t_vars *game, t_image *img, int new_hight, int new_width)
{
	int x;
	int y;
    int orig_x;
	int orig_y;
	
	img->addr =(int *) mlx_get_data_addr(img->image, \
		 &(int){0}, &(int){0}, &(int){0});
	img->scaled_image = mlx_new_image(game->mlx, \
		new_hight,new_width);
	img->scaled_addr = (int *)mlx_get_data_addr(img->scaled_image,\
		 &(int){0}, &(int){0}, &(int){0});
	y = 0;
	while( y < new_hight)
	{
		x = 0;
		while( x < new_width)
		{
			orig_x = (x * img->width) / new_width;
            orig_y = (y * img->hight) / new_hight;
			(img->scaled_addr)[y * new_width + x] = \
			(img->addr)[orig_y * img->width + orig_x];
			x++;
		}
		y++;
	}
}

void	fill_background(t_vars *game, t_image *img, char **map)
{
	int i;
	size_t x;
	size_t y;
	
	x = 0;
	y = 0;
	while (x < ft_strlen_d(map))
	{
		y = 0;
		while (y < ft_strlen(map[x]) )
		{
			i = mlx_put_image_to_window(game->mlx, game->win, img->scaled_image\
				,  y * img->scaled_hight , x * img->scaled_width);
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

