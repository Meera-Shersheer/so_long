/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:27:10 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 06:14:07 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_vars *game, t_image *img)
{
	char	*str;
	char	*s;

	s = ft_itoa(*(game->sprite->moves));
	str = ft_strjoin("Moves: ", s);
	mlx_string_put(game->mlx, game->win, img->scaled_hight / 2, \
		img->scaled_width / 2, 0x000000, str);
	mlx_string_put(game->mlx, game->win, img->scaled_hight / 2 + 1, \
		img->scaled_width / 2, 0x000000, str);
	mlx_string_put(game->mlx, game->win, img->scaled_hight / 2, \
		img->scaled_width / 2 + 1, 0x000000, str);
	free(str);
	free(s);
}

int	enemy_move(char **map, int i, int j)
{
	if (map[i][j] == 'M' && map[i][j - 1] == '0')
	{
		map[i][j - 1] = 'M';
		map[i][j] = '0';
	}
	else if (map[i][j] == 'N' && map[i][j + 1] == '0')
	{
		map[i][j + 1] = 'N';
		map[i][j] = '0';
		return (1);
	}
	else if (map[i][j] == 'M')
		map[i][j] = 'N';
	else if (map[i][j] == 'N')
		map[i][j] = 'M';
	return (0);
}

void	win(t_vars *game)
{
	ft_printf("You won with %d moves\n", ++(*(game->sprite->moves)));
	close_window(game);
}

void	draw_map(t_vars *game, t_sprites *sprites, char **map)
{
	size_t	x;
	size_t	y;
	t_image	*img;

	x = 0;
	y = 0;
	while (x < ft_strlen_d(map))
	{
		y = 0;
		while (y < ft_strlen(map[x]))
		{
			img = load_img_to_win(sprites, map, x, y);
			if (img == NULL)
				close_window(game);
			mlx_put_image_to_window(game->mlx, game->win, img->scaled_image \
				, y * img->scaled_hight, x * img->scaled_width);
			y++;
		}
		x++;
	}
	print_moves(game, img);
}

/* W->door_open |  D->door&player_frame | N->enemy */
t_image	*load_img_to_win(t_sprites *sprites, char **map, size_t x, size_t y)
{
	if (map[x][y] == '1')
		return (sprites->wall);
	if (map[x][y] == '0')
		return (sprites->ground);
	if (map[x][y] == 'E')
		return (sprites->exit);
	if (map[x][y] == 'C')
		return (sprites->collectable);
	if (map[x][y] == 'D')
		return (sprites->door_player);
	if (map[x][y] == 'W')
		return (sprites->door_open);
	if (map[x][y] == 'P')
		return (sprites->player);
	if (map[x][y] == 'N')
		return (sprites->enemy_R);
	if (map[x][y] == 'M')
		return (sprites->enemy_L);
	if (map[x][y] == 'R')
		return (sprites->player_R);
	if (map[x][y] == 'L')
		return (sprites->player_L);
	else
		return (NULL);
}
