/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:38:16 by gshim             #+#    #+#             */
/*   Updated: 2022/07/19 21:48:40 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void setScreen(t_game *g, unsigned int *screen)
{
	int y;
	int x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				screen[y * SCREEN_WIDTH + x] = g->map->floor_color;
			else if (y > SCREEN_HEIGHT/2)
				screen[y * SCREEN_WIDTH + x] = g->map->ceiling_color;
			else
				screen[y * SCREEN_WIDTH + x] = 0;
		}
	}
}

t_texture	getWallTexture(t_game *g)
{
	if (g->side == 0)
	{
		if (g->stepX == -1) // W
			return (g->map->tex[2]);
		else //E
			return (g->map->tex[3]);
	}
	else
	{
		if (g->stepY == -1) // N
			return (g->map->tex[0]);
		else // S
			return (g->map->tex[1]);
	}
}