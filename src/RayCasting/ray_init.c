/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:34:27 by gshim             #+#    #+#             */
/*   Updated: 2022/07/17 03:19:53 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_paint()
{
	// 그릴 지점 찾기.
	int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

	int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawStart < 0) drawStart = 0;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

	// color = (r * 256 * 256) + (g * 256) + b;
	int color ;
	switch(worldMap[mapX][mapY])
	{
		case 1:  color = RGB_Red;    break; //red
		case 2:  color = RGB_Green;  break; //green
		case 3:  color = RGB_Blue;   break; //blue
		case 4:  color = RGB_White;  break; //white
		default: color = RGB_Yellow; break; //yellow
	}

	//give x and y sides different brightness
	if(side == 1) {color = color / 2;}

	//draw the pixels of the stripe as a vertical line
	for(int i=drawStart;i<=drawEnd;i++)
		mlx_pixel_put(g->mlx, g->win, x, i, color);
}

void ray_DDA()
{
	// 벽에 닿을 때까지 광선발사
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (worldMap[mapX][mapY] > 0) hit = 1;
	}
	// 카메라평면~부딫친벽과의 거리
	if (side == 0)
		perpWallDist = (mapX - g->pX + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - g->pY + (1 - stepY) / 2) / rayDirY;
}

void ray_calc_

void ray_init(t_raycasting *ray, int x)
{
	// Declaration
	ray->cameraX = 2 * x / (double)(SCREEN_WIDTH-1) - 1;
	ray->rayDirX = g->dirX + g->planeX * ray->cameraX;
	ray->rayDirY = g->dirY + g->planeY * ray->cameraX;

	ray->mapX = (int)(g->pX);
	ray->mapY = (int)(g->pY);

	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}
