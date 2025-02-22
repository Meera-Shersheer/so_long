/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:53:20 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/22 20:39:03 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line_bonus.h"
# include "./Libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void		*image;
	void		*scaled_image;
	int			scaled_hight;
	int			scaled_width;
	int			*addr;
	int			*scaled_addr;
	int			hight;
	int			width;
}				t_image;

typedef struct s_sprites
{
	t_image		*ground;
	t_image		*wall;
	t_image		*exit;
	t_image		*collectable;
	t_image		*player;
	t_image		*door_player;
	t_image		*door_open;
	t_image		*player_l;
	t_image		*player_r;
	t_image		*enemy_r;
	t_image		*enemy_l;
	int			*collect;
	int			*total_c;
	int			*moves;
}				t_sprites;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_hight;
	int			win_width;
	t_sprites	*sprite;
	char		**map;
}				t_vars;

char	**check_map(t_vars *game, char **argv);
int	hooks(int key, t_vars *game);
void	update_map(char **map, int key, t_vars *game);
int	keys(t_vars *game, int key, int i, int j);
char	*read_map(t_vars *game, char *map_name);
char	**transform_into_matrix(t_vars *game, char *map, char **map_matrix);
void	exit_game(int code, char **map,t_vars *game);
void	ft_free(char **map);
size_t	ft_strlen_d(char **s);
void	load_image( t_vars	*game, char **map, t_sprites *sprites);
void	check_images(t_vars	*game);
void	load_resized_image( t_vars	*game, char **map, t_sprites *sprites);
void	resize_image(t_vars *game, t_image *img, int new_hight, int new_width);
void	render_game(char **map, t_vars *game, int moved);
void	load_xpm_image(t_vars *game, t_image *img, char *filename, int scaled_d);
void	sprites_init(t_vars *game, t_sprites *sprites, char **map);
void	sprites_destroy(t_vars *game, t_image *img);
int	close_window(t_vars *game);
void	load_data(t_vars *game, t_sprites *sprites, char **map);
int	move(t_vars *game, int i, int j, int direction);
void	win(t_vars *game);
void	draw_map(t_vars *game, t_sprites *sprites, char **map);
t_image	*load_img_to_win(t_sprites *sprites, char **map, size_t x, size_t y);
int	element_counter(char **map, char element, t_vars *game);
void	destroy_mlx(t_vars *game);
void	check_size(t_vars *game, char **map);
void	floodfill(char **map, int x, int y);
char	**cpy_matrix(char	**map, t_vars *game);
char	**check_invalid_path(char	**map, t_vars *game);
void	get_pos(t_vars *game, char element, int *i, int *j);
int	check_elements(char	**map, t_vars *game);
void	check_extenstion(char *file_name , t_vars *game);
char	**check_invalid_map(char **map, t_vars *game);
int	check_rectangular(char	**map, t_vars *game);
int	check_outline(char	**map, t_vars *game);
void	check_cutoff(char	*map, t_vars *game);
#endif
