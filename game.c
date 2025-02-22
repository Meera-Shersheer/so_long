/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:52:42 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 04:06:17 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*direction :0-> right, 1 -> up, 2->down , 3->left */
int	move(t_vars *game, int i, int j, int direction)
{
	char	**map;

	map = game->map;
	if (map[i][j] == 'D')
		map[i][j] = 'E';
	else
		map[i][j] = '0';
	if (direction == 0)
		j++;
	else if (direction == 1)
		i--;
	else if (direction == 2)
		i++;
	else if (direction == 3)
		j--;
	if (map[i][j] == 'C')
		(*(game->sprite->collect))++;
	if (map[i][j] == 'W')
		win(game);
	if (map[i][j] == 'E')
		map[i][j] = 'D';
	else
		map[i][j] = 'P';
	(*(game->sprite->moves))++;
	return (1);
}

void	win(t_vars *game)
{
	ft_printf("Moves: %d\n", ++(*(game->sprite->moves)));
	ft_printf("You won with %d moves\n", (*(game->sprite->moves)));
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
	ft_printf("Moves: %d\n", *(game->sprite->moves));
}

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
	else
		return (NULL);
}

int	element_counter(char **map, char element)
{
	int		counter;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	counter = 0;
	if (map == NULL || *map == NULL)
		exit_game(-1, NULL);
	while (i < ft_strlen_d(map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
