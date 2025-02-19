/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:02:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/19 21:45:50 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_xpm_image( t_vars	*game ,t_image	*img,char	*filename)
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
}

void sprites_init(t_sprites *sprites ,int scaled_h, int scaled_w, char **map)
{
	if(!sprites)
		exit_game(8, map);
	sprites->background = malloc(sizeof(t_image));
	sprites->ground = malloc(sizeof(t_image));
	sprites->wall = malloc(sizeof(t_image));
	sprites->player = malloc(sizeof(t_image));
	sprites->exit = malloc(sizeof(t_image));
	sprites->collectable = malloc(sizeof(t_image));
	if(!(sprites->wall) || !(sprites->background) || !(sprites->ground))
		exit_game(8, map);
	if(!(sprites->collectable) || !(sprites->exit) || !(sprites->player))
		exit_game(8, map);
	sprites->background->scaled_hight = scaled_h;
	sprites->background->scaled_width = scaled_w;
	sprites->ground->scaled_hight = scaled_h;
	sprites->ground->scaled_width = scaled_w;
	sprites->player->scaled_hight = scaled_h;
	sprites->player->scaled_width = scaled_w;
	sprites->wall->scaled_hight = scaled_h;
	sprites->wall->scaled_width = scaled_w;
	sprites->collectable->scaled_hight = scaled_h;
	sprites->collectable->scaled_width = scaled_w;
	sprites->exit->scaled_hight = scaled_h;
	sprites->exit->scaled_width = scaled_w;
}
