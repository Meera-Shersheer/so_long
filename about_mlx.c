/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:37:05 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/12 01:53:17 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//in makefile
//cc -Wall -Wextra -Werror about_mlx.c -Lminilibx-linux -lmlx -lXext -lX11 -Iminilibx-linux

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
         (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data	img;
    
    mlx = mlx_init();
    if (!mlx) {
        printf("Error: MiniLibX initialization failed!\n");
        return (1);
    }
    mlx_window = mlx_new_window(mlx, 1920,1080, "Hi There");
    if (!mlx_window) {
        printf("Error: Window creation failed!\n");
        return (1);
    }
     //(void)mlx_window;
        
    // mlx_pixel_put(mlx, mlx_window, 100, 100, 0xFF0000); // red

    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
         &img.line_length, &img.endian);
     my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
     mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
     
    mlx_loop(mlx);
}