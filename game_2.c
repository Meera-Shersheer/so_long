/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:54:26 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 17:01:25 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destoy_mlx(t_vars *game)
{
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit_game(7, game->map);
	}
}
