/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:38:16 by gshim             #+#    #+#             */
/*   Updated: 2022/07/20 01:16:17 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drawLine(t_game *g, t_texture wall_tex, unsigned int *data, unsigned int *screen, int x)
{
	for(int y = g->drawStart; y<g->drawEnd; y++)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		g->texY = (int)(g->texPos) & (wall_tex.height - 1);
		g->texPos += g->step;
		//Uint32 color = texture[texNum][texHeight * texY + texX];
		int color = data[wall_tex.height * g->texY + g->texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(g->side == 1) color = (color >> 1) & 8355711;
		screen[y * SCREEN_WIDTH + x] = color;
	}
}

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
