/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:06:24 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/23 06:18:17 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	render_game(char **map, t_vars *game, int moved)
{
	if (moved)
	{
		mlx_clear_window(game->mlx, game->win);
		draw_map(game, game->sprite, map);
		mlx_do_sync(game->mlx);
	}
}

void	destroy_mlx(t_vars *game)
{
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit_game(7, game->map);
	}
}

void	check_size(t_vars *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(game->mlx, &x, &y);
	if (y < (32 * (int)ft_strlen_d(map)))
	{
		destroy_mlx(game);
	}
	if (x < (32 * (int)ft_strlen((map)[0])))
	{
		destroy_mlx(game);
	}
}
