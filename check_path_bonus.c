/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:10:41 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 19:49:11 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)(ft_strlen_d(map)))
		return ;
	if (y >= (int)(ft_strlen(*map)))
		return ;
	if (map[x][y] == '1' || map[x][y] == 'N')
		return ;
	else
	{
		map[x][y] = '1';
		floodfill(map, x - 1, y);
		floodfill(map, x + 1, y);
		floodfill(map, x, y - 1);
		floodfill(map, x, y + 1);
	}
}

char	**check_invalid_path(t_vars *game, char	**map)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = 0;
	x = 0;
	check_size(game, map);
	map_cpy = cpy_matrix(map);
	get_pos(map, 'P', &x, &y);
	floodfill(map_cpy, x, y);
	if (element_counter(map_cpy, 'C') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	if (element_counter(map_cpy, 'E') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	ft_free(map_cpy);
	return (NULL);
}

char	**check_invalid_path(char	**map, t_vars *game)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = 0;
	x = 0;
	map_cpy = cpy_matrix(map);
	get_pos(map, 'P', &x, &y);
	floodfill(map_cpy, x, y);
	if (element_counter(map_cpy, 'C') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	if (element_counter(map_cpy, 'E') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	ft_free(map_cpy);
	return (NULL);
}

void	get_pos(char **map, char element, int *i, int *j)
{
	if (map == NULL || *map == NULL || !i || !j)
		exit_game(-1, NULL);
	*i = 0;
	*j = 0;
	while (*i < (int)ft_strlen_d(map))
	{
		*j = 0;
		while (*j < (int)ft_strlen(map[*i]))
		{
			if (map[*i][*j] == element)
				return ;
			(*j)++;
		}
		(*i)++;
	}
	*i = -1;
	*j = -1;
}

int	check_elements(char	**map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (map == NULL || *map == NULL)
		exit_game(-1, NULL);
	while (i < ft_strlen_d(map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' \
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'N')
				exit_game(2, map);
			j++;
		}
		i++;
	}
	return (0);
}
