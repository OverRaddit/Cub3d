/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:40 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 13:23:25 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_minimap(t_game *g, unsigned int *minimap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map->row)
	{
		j = -1;
		while (++j < g->map->col)
		{
			if (i == (int)g->pX && j == (int)g->pY)
				paint_grid(g, minimap, i * g->gridH, j * g->gridW, RGB_Red);
			else if (g->map->map_malloc[i][j] == '\0')
				break ;
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

void	paint_grid(t_game *g, unsigned int *minimap, int y, int x, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y + g->gridH)
	{
		j = -1;
		while (++j < x + g->gridW)
		{
			minimap[i * g->miniW + j] = color;
		}
	}
}
