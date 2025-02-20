/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:15:49 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/20 06:39:41 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc , char **argv)
{
	char	**map;
	t_vars	game = {0};
	t_sprites	sprites = {0};
	
    if (argc != 2)
        exit_game(-1, NULL);
    check_extenstion(argv[1]);
	map = transform_into_matrix(read_map(argv[1]));
	if (map == NULL)
		exit_game(-1,NULL);
	check_Invalid_map(map);
	check_Invalid_path(map);
	game.map = map;
	game.mlx = NULL;
	game.win = NULL;
	game.sprite = &sprites;	
	game.mlx = mlx_init();
   	if (!game.mlx) 
   		exit_game(6, map);
	game.win_hight = ft_strlen_d(map) * 80;
	game.win_width = ft_strlen(*map) * 80;
	game.win = mlx_new_window(game.mlx,game.win_width, game.win_hight, "so_long");
	if (!game.win)
		exit_game(7, map);
	//render_game(map, &game);
	load_image(&game, map, game.sprite);
	//fill_background(&game,sprites.background, map);
	game.sprite->collect = malloc (sizeof(int *));
	game.sprite->total_c = malloc (sizeof(int *));
	if (!(game.sprite->collect) || !(game.sprite->total_c))
		exit_game(-1, map);
	*(game.sprite->collect) = 0;
	*(game.sprite->total_c) = element_counter(map, 'C');
	draw_map(&game,game.sprite, map);
	mlx_key_hook(game.win, hooks, &game);
	//mlx_loop_hook(game.mlx,  hooks, &game);
	mlx_loop(game.mlx);
}

int hooks(int key, t_vars *game)
{
    if (key == XK_Escape)
    {
		ft_free(game->map);
		if (game->sprite)
        {
			sprites_destroy(game,game->sprite->background);
			sprites_destroy(game,game->sprite->wall);
			sprites_destroy(game,game->sprite->collectable);
			sprites_destroy(game,game->sprite->door_open);
			sprites_destroy(game,game->sprite->door_player);
			sprites_destroy(game,game->sprite->player);
			sprites_destroy(game,game->sprite->exit);
			sprites_destroy(game,game->sprite->ground);
			free(game->sprite->collect);
			free(game->sprite->total_c);	
		}
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
        exit(0);
    }
	if (key == XK_Up || key == XK_Right || key == XK_Left || key == XK_Down)
		update_map(game->map,key,game);
	if (key == XK_w || key == XK_d || key == XK_a || key == XK_s)
		update_map(game->map,key,game);	
	return(0);
}

void update_map(char **map , int key, t_vars *game)
{
	int i;
	int j;
	int moved = 0;
	
	i = 0;
	j = 0;
	get_pos(map, 'P' , &i, &j);
	if(i < 0 && j < 0)
		get_pos(map, 'D' , &i, &j);
	if(i >= 0 && j>= 0)
	{
		if ((key == XK_Up || key == XK_w )&& map[i - 1][j]  != '1')
			moved = move(game,i, j, 1);
		else if ((key ==  XK_Right || key == XK_d ) && map[i][j + 1]  != '1')
			moved = move(game,i, j,0);
		else if ((key ==  XK_Left || key == XK_a )  && map[i][j - 1]  != '1')
			moved = move(game,i, j, 3);
		else if ((key == XK_Down || key == XK_s ) && map[i + 1][j]  != '1')
			moved = move(game,i, j, 2);
	}
	if(*(game->sprite->collect) == *(game->sprite->total_c))
	{
		get_pos(map, 'E' , &i, &j);
		if(i >= 0 && j>= 0)
			map[i][j] = 'W';
	}
	if (moved)
	{
		mlx_clear_window(game->mlx, game->win);
		draw_map(game, game->sprite, map);
		mlx_do_sync(game->mlx);
	}
}

/*direction :0-> right, 1 -> up, 2->down , 3->left */
int move(t_vars *game,int i, int j, int direction)
{
	char **map = game->map;

	if(map[i][j]  == 'D')
		map[i][j] = 'E';
	else
		map[i][j] = '0';	
	
	if(direction == 0)
		j++;
	else if(direction ==1)
		i--;
	else if(direction == 2)
		i++;
	else if(direction == 3)
		j--;
	if(map[i][j]  == 'C')
		(*(game->sprite->collect))++;	
	if(map[i][j]  == 'W')
		exit(1);
	if(map[i][j]  == 'E')	
		map[i][j] = 'D';
	else
		map[i][j] = 'P';
	return (1);
} 




	// for (int i = 0;map[i]; i++)
	// {
	// 	printf("\"%s\"\n",map[i]);
	// }
void	render_game(char	**map, t_vars	*game)
{
	t_sprites	sprites;
	
	//(void)map;

	load_image(game, map, &sprites);

	fill_background(game,sprites.background, map);
	draw_map(game, &sprites, map);
}	


void	draw_map(t_vars *game, t_sprites *sprites, char **map)
{
	//int i;
	size_t x;
	size_t y;
	t_image	*img;
	
	x = 0;
	y = 0;
	while (x < ft_strlen_d(map))
	{
		y = 0;
		while (y < ft_strlen(map[x]) )
		{
			if(map[x][y] == '1')
				img = sprites->wall;
			if(map[x][y] == '0')
				img = sprites->ground;
			if(map[x][y] == 'E')
				img = sprites->exit;
			if(map[x][y] == 'C')
				img = sprites->collectable;
			if(map[x][y] == 'D')
				img = sprites->door_player;
			if(map[x][y] == 'W')
				img = sprites->door_open;	
			if(map[x][y] == 'P')
				img = sprites->player;
			if (  (int)x * img->scaled_width > game->win_hight || (int)y * img->scaled_hight > game->win_width)
				{
  				  printf("Error: Image coordinates out of bounds!\n");
    				return;
				}
			 mlx_put_image_to_window(game->mlx, game->win, img->scaled_image\
				, y * img->scaled_hight, x * img->scaled_width);
				// if (i != 0)
				// {
				// 	printf(" %p		%p		%p		%ld		%ld\n",game->mlx, game->win, img->scaled_image
				// 		, y * img->scaled_hight, x * img->scaled_width);
				// 	exit(1);
				// }
			y++;
		}	
		x++;
	}	
}