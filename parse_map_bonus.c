/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:38:50 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 16:52:19 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map_name)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_game(1, NULL);
	map = ft_strdup("");
	if (map == NULL)
		exit_game(-1, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = gnl_strjoin(map, line);
		if (map == NULL)
			exit_game(-1, NULL);
		free (line);
	}
	close (fd);
	return (map);
}

char	**transform_into_matrix(char *map, char **map_matrix)
{
	if (map == NULL)
		return (NULL);
	check_cutoff(map);
	map_matrix = ft_split(map, '\n');
	if (map_matrix == NULL)
	{
		free (map);
		exit_game(-1, map_matrix);
	}
	free (map);
	return (map_matrix);
}

void	exit_game(int code, char **map)
{
	write(2, "Error\n", 6);
	if (code == 0)
		ft_putendl_fd("The file extension is incorrect\n", 2);
	if (code == 1)
		perror("Error opening file ");
	if (code == 2)
		ft_putendl_fd("The map is Invalid\n", 2);
	if (code == 3)
		ft_putendl_fd("The map is not fully surrounded by walls\n", 2);
	if (code == 4)
		ft_putendl_fd("The map is cut\n", 2);
	if (code == 5)
		ft_putendl_fd("Invalid path\n", 2);
	if (code == 6)
		perror("MiniLibX initialization failed! ");
	if (code == 7)
		perror("Window creation failed! ");
	if (code == 8)
		ft_putendl_fd("the input is null\n", 2);
	if (code == 9)
		ft_putendl_fd("missing sprite's file\n", 2);
	if (map != NULL)
		ft_free(map);
	exit (1);
}

void	ft_free(char **map)
{
	size_t	row;

	row = 0;
	if (!map)
		return ;
	if (!(*map))
		return (free(map));
	while (row < ft_strlen_d(map))
	{
		free (map[row]);
		row++;
	}
	free (map);
}

size_t	ft_strlen_d(char **s)
{
	size_t	n;

	n = 0;
	if (s == NULL || *s == NULL)
		return (0);
	while (s[n] != NULL)
		n++;
	return (n);
}
