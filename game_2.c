/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:54:26 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/23 04:07:04 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx(t_vars *game)
{
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit_game(7, NULL);
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
		ft_free(map);
		destroy_mlx(game);
	}
	if (x < (32 * (int)ft_strlen((map)[0])))
	{
		ft_free(map);
		destroy_mlx(game);
	}
}
