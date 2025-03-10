/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:15:49 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/27 19:59:09 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		game;
	t_sprites	sprites;

	if (argc != 2)
		exit_game(-1, NULL);
	game.map = check_map(argv);
	check_images(&game);
	game.win = NULL;
	game.sprite = &sprites;
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_game(6, game.map);
	check_invalid_path(game.map, &game);
	game.win_hight = ft_strlen_d(game.map) * 32;
	game.win_width = ft_strlen(*(game.map)) * 32;
	game.win = mlx_new_window(game.mlx, game.win_width, \
	game.win_hight, "so_long");
	if (!game.win)
		destroy_mlx(&game);
	load_image(&game, game.map, game.sprite);
	load_data(&game, game.sprite, game.map);
	draw_map(&game, game.sprite, game.map);
	mlx_hook(game.win, 2, 1L << 0, hooks, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}

char	**check_map(char **argv)
{
	char	**map;
	char	*s;

	check_extenstion(argv[1]);
	s = read_map(argv[1]);
	if (s == NULL)
		exit_game(-1, NULL);
	map = NULL;
	map = transform_into_matrix(s, map);
	if (map == NULL)
	{
		if (s)
			free (s);
		exit_game(-1, map);
	}
	check_invalid_map(map);
	return (map);
}

int	hooks(int key, t_vars *game)
{
	if (key == XK_Escape)
		close_window(game);
	if (key == XK_Up || key == XK_Right || key == XK_Left || key == XK_Down)
		update_map(game->map, key, game);
	if (key == XK_w || key == XK_d || key == XK_a || key == XK_s)
		update_map(game->map, key, game);
	return (0);
}

void	update_map(char **map, int key, t_vars *game)
{
	int	i;
	int	j;
	int	moved;

	i = 0;
	j = 0;
	moved = 0;
	get_pos(map, 'P', &i, &j);
	if (i < 0 && j < 0)
		get_pos(map, 'D', &i, &j);
	if (i >= 0 && j >= 0)
		moved = keys(game, key, i, j);
	if (*(game->sprite->collect) == *(game->sprite->total_c))
	{
		get_pos(map, 'E', &i, &j);
		if (i >= 0 && j >= 0)
			map[i][j] = 'W';
	}
	render_game(map, game, moved);
}

int	keys(t_vars *game, int key, int i, int j )
{
	char	**map;

	map = game->map;
	if ((key == XK_Up || key == XK_w) && map[i - 1][j] != '1' )
		return (move(game, i, j, 1));
	else if ((key == XK_Right || key == XK_d) && map[i][j + 1] != '1')
		return (move(game, i, j, 0));
	else if ((key == XK_Left || key == XK_a) && map[i][j - 1] != '1')
		return (move(game, i, j, 3));
	else if ((key == XK_Down || key == XK_s) && map[i + 1][j] != '1')
		return (move(game, i, j, 2));
	else
		return (0);
}
