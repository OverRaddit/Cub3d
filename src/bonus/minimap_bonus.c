/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:40 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 18:33:02 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_minimap(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map->row)
	{
		j = -1;
		while (++j < g->map->col)
		{
			if (i == (int)g->px && j == (int)g->py)
				paint_grid(g, i * g->gridh, j * g->gridw, RGB_RED);
			else if (g->map->map_malloc[i][j] == '\0')
				break ;
			else if (g->map->map_malloc[i][j] == '0')
				paint_grid(g, i * g->gridh, j * g->gridw, RGB_WHITE);
			else if (g->map->map_malloc[i][j] == '1')
				paint_grid(g, i * g->gridh, j * g->gridw, 0);
			else
				paint_grid(g, i * g->gridh, j * g->gridw, 0);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->minimap.img, 0, 0);
}

void	paint_grid(t_game *g, int y, int x, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + g->gridh)
	{
		j = x - 1;
		while (++j < x + g->gridw)
		{
			g->minimap_data[i * g->miniw + j] = color;
		}
	}
}
