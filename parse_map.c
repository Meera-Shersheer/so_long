/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:38:50 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/19 21:31:15 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *read_map(char *map_name)
{
    int fd;
    char *line;
    char *map;

    
    fd = open(map_name,O_RDONLY);
    if (fd == -1)
		exit_game(1, NULL);
    map = ft_strdup("");
    if(map == NULL)
		exit_game(-1, NULL);
     while (1)
     {
		line = get_next_line(fd);
        if(line == NULL)
            break;
        map = gnl_strjoin(map, line);
		if(map == NULL)
			exit_game(-1, NULL);
        free(line);
     }
     //printf("%s",map);
    return (map);
}

char    **transform_into_matrix(char *map)
{
    char    **map_matrix;
    
    if (map == NULL)
        return(NULL);
    check_cutoff(map);     
    map_matrix = ft_split(map, '\n');
    if (map_matrix == NULL)
    {
        free (map);
        exit_game(-1, NULL);
    }
    free (map);    
    return (map_matrix);    
}

void    exit_game(int code, char **map)
{
	if (code == -1)
	{
		write(2, "Error\n", 6);
        exit(1);
	}
	if (code == 0)
	{
		write(2, "Error\n", 6);
        ft_printf("The file extension is incorrect\n");
        exit(1);
	}
	if (code == 1)
	{
		write(2, "Error\n", 6);
        perror("Error opening file ");
        exit(1);
	}
    if (code == 2)
	{
		write(2, "Error\n", 6);
        ft_printf("The map is Invalid\n");
        ft_free(map);
        exit(1);
	}
    exit_game_2(code, map);
}
void    exit_game_2(int code, char **map)
{
	if (code == 3)
	{
		write(2, "Error\n", 6);
        ft_printf("The map is not fully surrounded by walls\n");
        ft_free(map);
        exit(1);
	}
	if (code == 4)
	{
        write(2, "Error\n", 6);
        ft_printf("The map is cut\n");
        free(*map);
        exit(1);
    }
	if (code == 5)
    {
        write(2, "Error\n", 6);
        ft_printf("Invalid path\n");
        ft_free(map);
        exit(1);
	}
    if (code ==6)
	{
        write(2, "Error\n", 6);
        perror("MiniLibX initialization failed!\n");
        ft_free(map);
        exit(1);
	}
    if (code == 7)
	{
        write(2, "Error\n", 6);
        perror("Window creation failed!\n");
        ft_free(map);
        exit(1);
	}
    if (code == 8)
	{
        write(2, "Error\n", 6);
        printf("Error: the input is null\n");
        ft_free(map);
        exit(1);
	}

}

void    ft_free(char **map)
{
    size_t row;
    
    row = 0;
    if (!map || !(*map) )
        return ;
    while( row < ft_strlen_d(map))
    {
        free(map[row]);
        row++;
    }
    free(map);
}

size_t	ft_strlen_d(char **s)
{
	size_t	n;

	n = 0;
    if (s == NULL)
    {
        return (0);
    }
    while (s[n] != NULL)
    {
		n++;
    }
    return (n);
}