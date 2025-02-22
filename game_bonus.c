/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:52:42 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 06:15:17 by mshershe         ###   ########.fr       */
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
	fix_direction(direction, &i, &j);
	if (map[i][j] == 'C')
		(*(game->sprite->collect))++;
	enemy_patrol(map);
	if (map[i][j] == 'N' || map[i][j] == 'M')
		loss(game);
	if (map[i][j] == 'W')
		win(game);
	if (map[i][j] == 'E')
		map[i][j] = 'D';
	else
		move_2(map, i, j, direction);
	(*(game->sprite->moves))++;
	return (1);
}

void	fix_direction(int direction, int *i, int *j)
{
	if (direction == 0)
		(*j)++;
	else if (direction == 1)
		(*i)--;
	else if (direction == 2)
		(*i)++;
	else if (direction == 3)
		(*j)--;
}

int	move_2(char **map, int i, int j, int direction)
{
	if (direction == 0)
		map[i][j] = 'L';
	else if (direction == 3)
		map[i][j] = 'R';
	else if (direction == 1 || direction == 2)
		map[i][j] = 'P';
	return (0);
}

void	loss(t_vars *game)
{
	ft_printf("you've been killed, better luck next time\n");
	close_window(game);
}

/* direction=-1 -> left | direction = 1 -> right*/
void	enemy_patrol(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)ft_strlen_d(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == 'M' || map[i][j] == 'N')
				j += enemy_move(map, i, j);
			j++;
		}
		i++;
	}
}
