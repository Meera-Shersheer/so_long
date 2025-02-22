/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:49:32 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 20:17:32 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extenstion(char *file_name , t_vars *game)
{
	if (ft_strncmp(&(file_name[ft_strlen(file_name)- 4]), ".ber", 4) != 0)
		exit_game(0, NULL, game);
}

char	**check_invalid_map(char **map, t_vars *game)
{
	check_rectangular(map, game);
	check_outline(map, game);
	check_elements(map, game);
	if (element_counter(map, 'E') != 1 || element_counter(map, 'P') != 1)
		exit_game(2, map, game);
	if (element_counter(map, 'C') < 1)
		exit_game(2, map, game);
	return (NULL);
}

int	check_rectangular(char	**map, t_vars *game)
{
	size_t	i;
	size_t	j;

	if (map == NULL || *map == NULL)
		exit_game(-1, map, game);
	j = 0;
	i = ft_strlen(map[j]);
	while (j < ft_strlen_d(map))
	{
		if (i != ft_strlen(map[j]))
			exit_game(2, map, game);
		j++;
	}
	return (0);
}

int	check_outline(char	**map, t_vars *game)
{
	size_t	col;
	size_t	row;

	if (map == NULL || *map == NULL)
		exit_game(-1, NULL, game);
	row = 0;
	col = 0;
	while (row < ft_strlen_d(map))
	{
		if (row == 0 || row == ft_strlen_d(map) - 1)
		{
			col = 0;
			while (col < ft_strlen(map[row]))
			{
				if (map[row][col] != '1')
					exit_game(3, map, game);
				col++;
			}
		}
		if (map[row][0] != '1' || map[row][ft_strlen(map[row]) - 1] != '1' )
			exit_game(3, map, game);
		row++;
	}
	return (0);
}

void	check_cutoff(char	*map, t_vars *game)
{
	int	i;
	int	j;

	if (map == NULL)
		exit_game(-1, NULL, game);
	i = 0;
	j = ft_strlen(map);
	if (map[0] == '\n')
	{
		free(map);
		exit_game(4, NULL, game);
	}
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (i > 0 && map[i - 1] == '\n')
			{
				free(map);
				exit_game(4, NULL, game);
			}
		}
		i++;
	}
}
