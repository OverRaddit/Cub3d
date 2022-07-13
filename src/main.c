/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/13 18:28:39 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_memset(&map, 0, sizeof(t_map));
		parse(&map, argv[1]);
		for (int i = 0;i < 4;i++)
			printf("tex_path : %s\n", map.tex[i].tex_path);
		printf("\n");
		printf("ceilling color: %#x\n", map.ceiling_color);
		printf("floor color: %#x\n", map.floor_color);
		int y = -1;
		while (map.map[++y])
		{
			int x = -1;
			while (map.map[y][++x])
				printf("%c", map.map[y][x]);
			printf("\n");
		}
	}
	return 0;
}
