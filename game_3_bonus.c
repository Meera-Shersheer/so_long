/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:06:24 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 16:59:35 by mshershe         ###   ########.fr       */
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

void	destoy_mlx(t_vars *game)
{
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit_game(7, game->map);
	}
}
