/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:53:20 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/17 18:25:58 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "./Libft/libft.h"
#include "./Libft/get_next_line_bonus.h"
#include "./Libft/ft_printf.h"


char	*read_map(char *map_name);
void    exit_game(int code, char **map);
void    exit_game_2(int code, char **map);
void	check_extenstion(char *file_name);
char    **transform_into_matrix(char *map);
int	check_rectangular(char	**map);
int	check_outline(char	**map);
char	**check_Invalid_map(char	**map);
void    ft_free(char **map);
size_t	ft_strlen_d(char **s);
void	check_cutoff(char	*map);
int	element_counter(char	**map, char	element);

#endif