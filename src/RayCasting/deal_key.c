/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/20 01:33:29 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int moveable(t_game *game, double nx, double ny)
{
	if (game->map->map_malloc[(int)nx][(int)ny] > '0')
	{
		//printf("(%d, %d) is wall\n", (int)nx, (int)ny);
		return 0;
	}
	else
		return 1;
}

void	move(t_game *g, double angle)
{
	double nx,ny;

	// 이동할 좌표를 구한다.
	nx = g->pX + (g->dirX * cos(angle) - g->dirY * sin(angle)) * M_UNIT;
	ny = g->pY + (g->dirX * sin(angle) + g->dirY * cos(angle)) * M_UNIT;
	// 이동할 수 있는 좌표인지 검증 후 최신화한다.
	if (!moveable(g, nx, ny)
		|| !moveable(g, nx + g->planeX * 1/4, ny + g->planeY * 1/4)
		|| !moveable(g, nx - g->planeX * 1/4, ny - g->planeY * 1/4)
		|| !moveable(g, nx + (g->planeX * cos(M_PI_2) - g->planeY * sin(M_PI_2)) * 1/4, ny + (g->planeX * sin(M_PI_2) + g->planeY * cos(M_PI_2)) * 1/4)
		|| !moveable(g, nx - (g->planeX * cos(M_PI_2) - g->planeY * sin(M_PI_2)) * 1/4, ny - (g->planeX * sin(M_PI_2) + g->planeY * cos(M_PI_2)) * 1/4))
		return ;
	g->pX = nx;
	g->pY = ny;
}

void	rotate(t_game *g, double angle)
{
	double tempX,tempY;

	// 플레이어의 방향벡터를 최신화한다.
	tempX = g->dirX;
	tempY = g->dirY;
	g->dirX = tempX * cos(angle) - tempY * sin(angle);
	g->dirY = tempX * sin(angle) + tempY * cos(angle);

	// 카메라 평면을 어떻게.....?
	tempX = g->planeX;
	tempY = g->planeY;
	g->planeX = tempX * cos(angle) - tempY * sin(angle);
	g->planeY = tempX * sin(angle) + tempY * cos(angle);

}

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_event(game->map);
	else if (key_code == KEY_UP || key_code == KEY_W)
		move(game, 0);
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		move(game, M_PI);
	else if (key_code == KEY_A)
		move(game, M_PI_2);
	else if (key_code == KEY_D)
		move(game, -M_PI_2);
	else if (key_code == KEY_RIGHT)
		rotate(game, -R_UNIT);
	else if (key_code == KEY_LEFT)
		rotate(game, R_UNIT);
	return (0);
}
