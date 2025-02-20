/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:02:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/20 06:08:56 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_xpm_image( t_vars	*game ,t_image	*img,char *filename ,int scaled_d)
{
	if(!game || !(game->mlx) || !filename || !img)
	{
        printf("Error: the input is null\n");
		exit(1);
    }
	img->image = mlx_xpm_file_to_image(game->mlx, filename, &(img->hight), &(img->width));
	if(img->image == NULL)
	{
        printf("Error: mlx_xpm_file_to_image failed\n");
		exit(1);
    }
	img->scaled_hight = scaled_d;
	img->scaled_width = scaled_d;
}

void sprites_init(t_sprites *sprites , char **map)
{
	if(!sprites)
		exit_game(8, map);
	sprites->background = malloc(sizeof(t_image));
	sprites->ground = malloc(sizeof(t_image));
	sprites->wall = malloc(sizeof(t_image));
	sprites->player = malloc(sizeof(t_image));
	sprites->exit = malloc(sizeof(t_image));
	sprites->collectable = malloc(sizeof(t_image));
	sprites->door_player = malloc(sizeof(t_image));
	sprites->door_open = malloc(sizeof(t_image));
	if(!(sprites->door_player) || !(sprites->door_open))
		exit_game(8, map);
	if(!(sprites->wall) || !(sprites->background) || !(sprites->ground))
		exit_game(8, map);
	if(!(sprites->collectable) || !(sprites->exit) || !(sprites->player))
		exit_game(8, map);
}

void sprites_destroy(t_vars *game, t_image *img)
{
	if (img)
	{
		mlx_destroy_image(game->mlx,img->image);
		mlx_destroy_image(game->mlx,img->scaled_image);
		free(img);
	}
}