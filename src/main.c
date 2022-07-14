/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/14 21:58:38 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	t_map	map;

// 	if (argc != 2)
// 		ft_putendl_fd("Error", 2);
// 	else
// 	{
// 		ft_memset(&map, 0, sizeof(t_map));
// 		parse(&map, argv[1]);
// 		for (int i = 0;i < 4;i++)
// 			printf("tex_path : %s\n", map.tex[i].tex_path);
// 		printf("\n");
// 		printf("ceilling color: %#x\n", map.ceiling_color);
// 		printf("floor color: %#x\n", map.floor_color);
// 		int y = -1;
// 		while (map.map[++y])
// 		{
// 			int x = -1;
// 			while (map.map[y][++x])
// 				printf("%c", map.map[y][x]);
// 			printf("\n");
// 		}
// 	}
// 	return 0;
// }

// gshim's main
int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_memset(&map, 0, sizeof(t_map));
		parse(&map, argv[1]);
		for (int i = 0;i < 4;i++)
			printf("tex_path : %s\n", map.tex[i].tex_path_malloc);
		printf("\n");
		printf("ceilling color: %#x\n", map.ceiling_color);
		printf("floor color: %#x\n", map.floor_color);
		int y = -1;
		while (map.map_malloc[++y])
		{
			int x = -1;
			while (map.map_malloc[y][++x])
				printf("%c", map.map_malloc[y][x]);
			printf("\n");
		}
	}
	window_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	//mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &closed, &game);
	while(1)
		;

	return 0;
}
