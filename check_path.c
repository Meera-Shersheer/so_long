/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:10:41 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 20:55:06 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)(ft_strlen_d(map)))
		return ;
	if (y >= (int)(ft_strlen(*map)))
		return ;
	if (map[x][y] == '1')
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

char	**cpy_matrix(char	**map, t_vars *game)
{
	size_t	i;
	char	**map_cpy;

	i = 0;
	if (map == NULL || *map == NULL)
		exit_game(-1, map, game);
	map_cpy = malloc(sizeof(char *) * (ft_strlen_d(map) + 1));
	if (map_cpy == NULL)
		exit_game(-1, map, game);
	while (i < ft_strlen_d(map))
	{
		map_cpy[i] = ft_strdup((map[i]));
		if (!map_cpy[i])
		{
			ft_free(map_cpy);
			exit_game(-1, map, game);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

char	**check_invalid_path(char	**map, t_vars *game)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = 0;
	x = 0;
	map_cpy = cpy_matrix(map, game);
	get_pos(game, 'P', &x, &y);
	floodfill(map_cpy, x, y);
	if (element_counter(map_cpy, 'C', game) != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	if (element_counter(map_cpy, 'E', game) != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy, game);
	}
	ft_free(map_cpy);
	return (NULL);
}

void	get_pos(t_vars *game, char element, int *i, int *j)
{
	char	**map;

	if (!game)
		exit_game(-1, NULL, game);
	map = game->map;
	if (map == NULL || *map == NULL || !i || !j)
		exit_game(-1, NULL, game);
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

int	check_elements(char	**map, t_vars *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (map == NULL || *map == NULL)
		exit_game(-1, NULL, game);
	while (i < ft_strlen_d(map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' \
				&& map[i][j] != 'C' && map[i][j] != 'E')
				exit_game(2, map, game);
			j++;
		}
		i++;
	}
	return (0);
}