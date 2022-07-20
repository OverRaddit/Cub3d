/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:40 by gshim             #+#    #+#             */
/*   Updated: 2022/07/20 21:10:26 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_minimap(t_game *g, unsigned int *minimap)
{
	for(int i=0;i<g->map->row;i++)
	{
		for(int j=0;j<g->map->col;j++)
		{
			if (i == (int)g->pX && j == (int)g->pY)
				paint_grid(g, minimap, i * g->gridH, j * g->gridW, RGB_Red);
			else if (g->map->map_malloc[i][j] == '\0') // 개행 이후는 건드리지 않는다.
				break;
			else if (g->map->map_malloc[i][j] == '0')
				paint_grid(g, minimap, i * g->gridH, j * g->gridW, RGB_White);
			else if (g->map->map_malloc[i][j] == '1')
				paint_grid(g, minimap, i * g->gridH, j * g->gridW, RGB_Green);
			else
				paint_grid(g, minimap, i * g->gridH, j * g->gridW, 0);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->minimap.img, 0, 0);
}

void	paint_grid(t_game *g, unsigned int* minimap, int y, int x, int color)
{
	for(int i=y;i<y + g->gridH;i++)
	{
		for(int j=x;j<x + g->gridW;j++)
		{
			minimap[i * g->miniW + j] = color;
		}
	}
}