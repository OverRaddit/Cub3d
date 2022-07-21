/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:38:16 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 16:16:15 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawline(t_game *g, t_texture wall_tex, unsigned int *data, unsigned int *screen, int x)
{
	int	color;
	int	y;

	y = g->drawStart - 1;
	while (++y < g->drawEnd)
	{
		g->texY = (int)(g->texPos) & (wall_tex.height - 1);
		g->texPos += g->step;
		color = data[wall_tex.height * g->texY + g->texX];
		if (g->side == 1)
			color = (color >> 1) & 8355711;
		screen[y * SCREEN_WIDTH + x] = color;
	}
}

void	setscreen(t_game *g, unsigned int *screen)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				screen[y * SCREEN_WIDTH + x] = g->map->floor_color;
			else if (y > SCREEN_HEIGHT / 2)
				screen[y * SCREEN_WIDTH + x] = g->map->ceiling_color;
			else
				screen[y * SCREEN_WIDTH + x] = 0;
		}
	}
}

// W E N S
t_texture	getwalltexture(t_game *g)
{
	if (g->side == 0)
	{
		if (g->stepX == -1)
			return (g->map->tex[2]);
		else
			return (g->map->tex[3]);
	}
	else
	{
		if (g->stepY == -1)
			return (g->map->tex[0]);
		else
			return (g->map->tex[1]);
	}
}
