/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:00:36 by gshim             #+#    #+#             */
/*   Updated: 2022/07/19 22:04:38 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_cal_init(t_game *g, int x)
{
	g->cameraX = 2 * x / (double)(SCREEN_WIDTH-1) - 1;		// ?? 분모는 w가 아니라 w-1아닌가?
	g->rayDirX = g->dirX + g->planeX * g->cameraX;
	g->rayDirY = g->dirY + g->planeY * g->cameraX;
	g->mapX = (int)(g->pX);
	g->mapY = (int)(g->pY);
	g->deltaDistX = fabs(1 / g->rayDirX);
	g->deltaDistY = fabs(1 / g->rayDirY);
	g->hit = 0;
}

void	getSideDist(t_game *g)
{
	if (g->rayDirX < 0)
	{
		g->stepX = -1;
		g->sideDistX = (g->pX - g->mapX) * g->deltaDistX;
	}
	else
	{
		g->stepX = 1;
		g->sideDistX = (g->mapX + 1.0 - g->pX) * g->deltaDistX;
	}
	if (g->rayDirY < 0)
	{
		g->stepY = -1;
		g->sideDistY = (g->pY - g->mapY) * g->deltaDistY;
	}
	else
	{
		g->stepY = 1;
		g->sideDistY = (g->mapY + 1.0 - g->pY) * g->deltaDistY;
	}
}

void	DDA(t_game *g)
{
	while (g->hit == 0)
	{
		if (g->sideDistX < g->sideDistY)
		{
			g->sideDistX += g->deltaDistX;
			g->mapX += g->stepX;
			g->side = 0;
		}
		else
		{
			g->sideDistY += g->deltaDistY;
			g->mapY += g->stepY;
			g->side = 1;
		}
		if (g->map->map_malloc[g->mapX][g->mapY] > '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpWallDist = g->sideDistX - g->deltaDistX;
	else
		g->perpWallDist = g->sideDistY - g->deltaDistY;
}

void	getDrawPoint(t_game *g)
{
	g->lineHeight = (int)(SCREEN_HEIGHT / g->perpWallDist);
	g->drawStart = -1 * g->lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (g->drawStart < 0) g->drawStart = 0;
			g->drawEnd = g->lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (g->drawEnd >= SCREEN_HEIGHT) g->drawEnd = SCREEN_HEIGHT - 1;
}