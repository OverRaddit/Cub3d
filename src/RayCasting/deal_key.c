/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/20 17:50:40 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=========================
// 현재 사용하는 map은 임시 더미맵이다. 파싱한 맵이 아니다.
//=========================
static int moveable(t_game *game, double nx, double ny)
{
	int x;
	int y;

	x = (int)nx;
	y = (int)ny;
	if (x < 0 || y < 0 || x >= game->map->row || y >= game->map->col)
		return 1;
	if (game->map->map_malloc[x][y] > '0')
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
	// 검증하는 좌표는 상단 좌좌/우우측측, 하하단  좌좌/우우측측
	if (!moveable(g, nx, ny)
		|| !moveable(g, -nx + g->planeX * 1/4, ny + g->planeY * 1/4)
		|| !moveable(g, nx + g->planeX * 1/4, ny + g->planeY * 1/4)
		|| !moveable(g, -nx + g->planeX * 1/4, ny - g->planeY * 1/4)
		|| !moveable(g, nx + g->planeX * 1/4, ny - g->planeY * 1/4))
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
	// if (key_code == KEY_ESC)
	// 	closed(3);
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
	// mlx_put_image_to_window_scale(game->mlx, game->win, game->img.img,
	// 	1 * 32, 4 * 32, 32, 32,
	// 	game->px * 64, game->py * 64, 64, 64, 0xFFFFFF);
	// print_status(game);
	//printf("Key Event\n");
	return (0);
}
