/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:10:41 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/20 04:41:01 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map , int x , int y)
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
		floodfill(map , x - 1 , y);
		floodfill(map , x + 1 , y);
		floodfill(map , x , y - 1);
		floodfill(map , x , y + 1);
	}
}

char	**cpy_matrix(char	**map)
{
	size_t	i;
	char	**map_cpy;

	i = 0;
	if (map == NULL || *map == NULL)
		exit_game(-1, map);
	map_cpy = malloc(sizeof(char *)*(ft_strlen_d(map) + 1));
	if (map_cpy == NULL)
		exit_game(-1, map);	
	while (i < ft_strlen_d(map))
	{
		map_cpy[i] = ft_strdup((map[i]));
		i++;
	}
	map_cpy[i] = NULL;
	return(map_cpy);
}

char	**check_Invalid_path(char	**map)
{
	char	**map_cpy;
	int x;
	int y;
	
	y = 0;
	x = 0;
	map_cpy = cpy_matrix(map);
	get_pos(map, 'P', &x, &y);
	floodfill(map_cpy , x , y);
	if (element_counter(map_cpy, 'C') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy);
	}
	if (element_counter(map_cpy, 'E') != 0)
	{
		ft_free(map);
		exit_game(5, map_cpy);
	}
	ft_free(map_cpy);
	return (NULL);
}

void	get_pos(char **map, char element , int *i, int *j)
{

	if (map == NULL || *map == NULL || !i || !j)
		exit_game(-1, NULL);
	*i = 0;
	*j = 0;	
	while(*i < (int)ft_strlen_d(map))
	{
		*j = 0;
		while (*j < (int)ft_strlen(map[*i]) )
		{
			if (map[*i][*j] == element)
				return;
			(*j)++;
		}	
		(*i)++;
	}
	*i = -1;
	*j = -1;	
}
