/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:38:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/19 06:07:30 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_image( t_vars	*game , char **map,t_sprites *sprites)
{
	t_image	wall;
	t_image	ground;
	t_image	background;
	t_image	collectable;
	t_image	exit_door;
	t_image	player;
	int scaled_hight = 80;
	int scaled_width = 80;
	(void)map;
	// load_xpm_image( game ,char	*filename,int new_hight, int new_width);
	// load_xpm_image( game ,char	*filename,int new_hight, int new_width);
	// load_xpm_image( game ,char	*filename,int new_hight, int new_width);
	// load_xpm_image( t_vars	*game ,char	*filename,int new_hight, int new_width);
	wall.image = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", \
		 &(wall.hight), &(wall.width));
	if(wall.image == NULL)
   		exit(1);
	sprites->wall = &wall;
	background.image = mlx_xpm_file_to_image(game->mlx, "./sprites/background01.xpm", \
			&(background.hight), &(background.width));
	 if(background.image == NULL)
   		exit(1);
	sprites->background = &background;
	collectable.image = mlx_xpm_file_to_image(game->mlx, "./sprites/collectable1.xpm", \
		&(collectable.hight), &(collectable.width));
 	if(collectable.image == NULL)
	   exit(1);
	sprites->collectable = &collectable;
	ground.image = mlx_xpm_file_to_image(game->mlx, "./sprites/Grass.xpm", \
		&(ground.hight), &(ground.width));
		if (ground.image == NULL)
   		exit(1);
	sprites->ground = &ground;

	exit_door.image = mlx_xpm_file_to_image(game->mlx, "./sprites/door/Doors_closed.xpm", \
	&(exit_door.hight), &(exit_door.width));
	if(exit_door.image == NULL)
	   exit(1);
	sprites->exit = &exit_door;
	player.image = mlx_xpm_file_to_image(game->mlx, "./sprites/player/player_front_3.xpm", \
	&(player.hight), &(player.width));
	if(player.image == NULL)
	   exit(1);
	sprites->player = &player;
	resize_image(game , sprites->background, scaled_hight, scaled_width);
	resize_image(game ,sprites->collectable,scaled_hight,scaled_width);
	resize_image(game ,sprites->exit,scaled_hight,scaled_width);
	resize_image(game ,sprites->ground,scaled_hight,scaled_width);
	resize_image(game ,sprites->player,scaled_hight,scaled_width);
	resize_image(game ,sprites->wall,scaled_hight,scaled_width);

	fill_background(game,sprites->background, map);
	draw_map(game, sprites, map);


}
void resize_image(t_vars *game, t_image *img, int new_hight, int new_width)
{
	int x;
	int y;
    int orig_x;
	int orig_y;
	
	img->scaled_hight = new_hight;
	img->scaled_width = new_width;
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

