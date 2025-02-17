/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:15:49 by mshershe          #+#    #+#             */
/*   Updated: 2025/02/17 04:19:38 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc , char **argv)
{
	char	**map;
	
    if (argc != 2)
        exit_game(-1, NULL);
    check_extenstion(argv[1]);
	map = transform_into_matrix(read_map(argv[1]));
	if (map == NULL)
		exit_game(-1,NULL);
	check_Invalid_map(map);

	// for (int i = 0;map[i]; i++)
	// {
	// 	printf("\"%s\"\n",map[i]);
	// }


    //void    *mlx;
   // mlx = mlx_init();
   
}

