/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:37:05 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/15 05:37:29 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//in makefile
//cc -Wall -Wextra -Werror about_mlx.c -Lminilibx-linux -lmlx -lXext -lX11 -Iminilibx-linux

#include <mlx.h>
#include <stdio.h>
#include <X11/X.h>
#include <stdlib.h>
/*
#define ESC_KEY 65307

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	
			t_data;
            
int mouse_hook(int button, int x, int y, t_vars *vars)
{
    (void)vars;
    printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);

    if (button == 1) // Left click
    {
        printf("Left click detected!\n");
    }
    else if (button == 3) // Right click
    {
        printf("Right click detected!\n");
    }
    return (0);
}  
         
int	key_hook(int keycode, 	t_vars *vars)
{
    printf("Key pressed: %d\n", keycode);
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
	return (0);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
         (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    t_vars     vars;   
    t_data	img;
    
    vars.mlx = mlx_init();
    if (!vars.mlx) {
        printf("Error: MiniLibX initialization failed!\n");
        return (1);
    }
    vars.win = mlx_new_window(vars.mlx, 1920,1080, "Hi There");
    if (!vars.win) {
        printf("Error: Window creation failed!\n");
        return (1);
    }
     //(void)mlx_window;
        
    // mlx_pixel_put(mlx, mlx_window, 100, 100, 0xFF0000); // red

    img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
         &img.line_length, &img.endian);
     my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
     mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
     mlx_key_hook(vars.win, key_hook, &vars);
     mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
}
*/
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_1(int keycode, t_vars *vars)
{
    (void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_1, &vars);
	mlx_loop(vars.mlx);
}
*/
