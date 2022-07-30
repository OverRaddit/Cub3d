/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:00:36 by gshim             #+#    #+#             */
/*   Updated: 2022/07/30 11:30:51 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_cal_init(t_game *g, int x)
{
	g->camerax = 2 * x / (double)(SCREEN_WIDTH - 1) - 1;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)(g->px);
	g->mapy = (int)(g->py);
	g->deltadistx = fabs(1 / g->raydirx);
	g->deltadisty = fabs(1 / g->raydiry);
	g->hit = 0;
}

void	getsidedist(t_game *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->px - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->px) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->py - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->py) * g->deltadisty;
	}
}

void	dda(t_game *g)
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->map->map_malloc[g->mapx][g->mapy] > '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = g->sidedistx - g->deltadistx;
	else
		g->perpwalldist = g->sidedisty - g->deltadisty;
}

void	getdrawpoint(t_game *g)
{
	g->lineheight = (int)(SCREEN_HEIGHT / g->perpwalldist);
	g->drawstart = -1 * g->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (g->drawend >= SCREEN_HEIGHT)
		g->drawend = SCREEN_HEIGHT - 1;
}

void	cal_texture(t_game *g, t_texture *wall_tex)
{
	if (g->side == 0)
		g->wallx = g->py + g->perpwalldist * g->raydiry;
	else
		g->wallx = g->px + g->perpwalldist * g->raydirx;
	g->wallx -= floor((g->wallx));
	g->texx = (int)(g->wallx * (double)(wall_tex->width));
	if (g->side == 0 && g->raydirx > 0)
		g->texx = wall_tex->width - g->texx - 1;
	if (g->side == 1 && g->raydiry < 0)
		g->texx = wall_tex->width - g->texx - 1;
	g->step = 1.0 * wall_tex->height / g->lineheight;
	g->texpos = (g->drawstart - SCREEN_HEIGHT / 2 + g->lineheight / 2);
	g->texpos *= g->step;
}
