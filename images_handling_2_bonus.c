/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:02:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 20:24:25 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_xpm_image(t_vars *game, t_image *img, char *filename, int scaled_d)
{
	if (!game || !(game->mlx) || !filename || !img)
		exit_game (8, game->map, game);
	img->image = mlx_xpm_file_to_image(game->mlx, filename, \
		&(img->hight), &(img->width));
	if (img->image == NULL)
	{
		ft_printf("Error: failed to load the images\n");
		exit_game(-1, game->map, game);
	}
	img->scaled_hight = scaled_d;
	img->scaled_width = scaled_d;
}

void	sprites_init(t_vars *game, t_sprites *sprites, char **map)
{
	if (!sprites)
		exit_game(8, map, game);
	sprites->ground = malloc(sizeof(t_image));
	sprites->wall = malloc(sizeof(t_image));
	sprites->player = malloc(sizeof(t_image));
	sprites->exit = malloc(sizeof(t_image));
	sprites->collectable = malloc(sizeof(t_image));
	sprites->door_player = malloc(sizeof(t_image));
	sprites->door_open = malloc(sizeof(t_image));
	sprites->enemy_r = malloc(sizeof(t_image));
	sprites->enemy_l = malloc(sizeof(t_image));
	sprites->player_l = malloc(sizeof(t_image));
	sprites->player_r = malloc(sizeof(t_image));
	if (!(sprites->door_player) || !(sprites->door_open))
		exit_game(8, map, game);
	if (!(sprites->wall) || !(sprites->ground) || !(sprites->player_l))
		exit_game(8, map, game);
	if (!(sprites->collectable) || !(sprites->exit) || !(sprites->enemy_r))
		exit_game(8, map, game);
	if (!(sprites->enemy_l) || !(sprites->player) || !(sprites->player_r))
		exit_game(8, map, game);
}

void	sprites_destroy(t_vars *game, t_image *img)
{
	if (img)
	{
		mlx_destroy_image(game->mlx, img->image);
		mlx_destroy_image(game->mlx, img->scaled_image);
		free(img);
	}
}

int	close_window(t_vars *game)
{
	ft_free(game->map);
	if (game->sprite)
	{
		sprites_destroy(game, game->sprite->wall);
		sprites_destroy(game, game->sprite->collectable);
		sprites_destroy(game, game->sprite->door_open);
		sprites_destroy(game, game->sprite->door_player);
		sprites_destroy(game, game->sprite->player);
		sprites_destroy(game, game->sprite->exit);
		sprites_destroy(game, game->sprite->ground);
		sprites_destroy(game, game->sprite->enemy_l);
		sprites_destroy(game, game->sprite->enemy_r);
		sprites_destroy(game, game->sprite->player_r);
		sprites_destroy(game, game->sprite->player_l);
		free(game->sprite->collect);
		free(game->sprite->total_c);
		free(game->sprite->moves);
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
	return (0);
}

void	load_data(t_vars *game, t_sprites *sprites, char **map)
{
	game->sprite->collect = malloc (sizeof(int *));
	game->sprite->total_c = malloc (sizeof(int *));
	game->sprite->moves = malloc (sizeof(int *));
	if (!(sprites->collect) || !(sprites->total_c) || !(sprites->moves))
//		exit_game(-1, map, game); use close window 
	*(game->sprite->collect) = 0;
	*(game->sprite->moves) = 0;
	*(game->sprite->total_c) = element_counter(map, 'C');
}
