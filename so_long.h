/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:53:20 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/20 06:37:04 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_image
{
	void		*image;
	void		*scaled_image;
	int		scaled_hight;
	int		scaled_width;
	int	*addr;
	int	*scaled_addr;
	int			hight;
	int			width;
}				t_image;

typedef struct s_sprites
{
	t_image		*background;
	t_image		*ground;
	t_image		*wall;
	t_image		*exit;
	t_image		*collectable;
	t_image		*player;
	t_image		*door_player;
	t_image		*door_open;
	int			*collect;
	int			*total_c;
}				t_sprites;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int	win_hight;
	int win_width;
	t_sprites	*sprite;
	char	**map;
}				t_vars;

#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
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
void	floodfill(char **map , int x , int y);
char	**cpy_matrix(char	**map);
char	**check_Invalid_path(char	**map);
void	get_pos(char **map, char element , int *i, int *j);
void	render_game(char	**map, t_vars	*game);
void load_image( t_vars	*game , char **map,t_sprites *sprites);
void resize_image(t_vars *game, t_image *img, int new_hight, int new_width);
void	fill_background(t_vars *game, t_image *img, char **map);
void	draw_map(t_vars *game, t_sprites *sprites, char **map);
void load_xpm_image( t_vars	*game ,t_image	*img,char *filename ,int scaled_d);
void sprites_init(t_sprites *sprites , char **map);
int hooks(int keycode, t_vars *game);
void update_map(char **map , int key, t_vars *game);
int move(t_vars *game,int i, int j, int direction);
void sprites_destroy(t_vars *game, t_image *img);
#endif