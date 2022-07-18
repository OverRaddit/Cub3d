/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/19 02:27:28 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=========================
// 현재 사용하는 map은 임시 더미맵이다. 파싱한 맵이 아니다.
//=========================
static int moveable(t_game *game, double nx, double ny)
{
	// 맵 검증이 완벽하다면 인덱스 체크는 필요없다.
	// if (ny < 0 || nx < 0 || ny > game->map->col || nx > game->map->row)
	// {
	// 	printf("Out of Index\n");
	// 	return 0;
	// }
	if (game->map->map_malloc[(int)nx][(int)ny] > '0')
	{
		//printf("(%d, %d) is wall\n", (int)nx, (int)ny);
		return 0;
	}
	else
		return 1;
}

void	move(t_game *game, double angle)
{
	double nx,ny;

	// 이동할 좌표를 구한다.
	(void)angle;
	// nx = game->pX + game->dirX * M_UNIT;
	// ny = game->pY + game->dirY * M_UNIT;
	nx = game->pX + (game->dirX * cos(angle) - game->dirY * sin(angle)) * M_UNIT;
	ny = game->pY + (game->dirX * sin(angle) + game->dirY * cos(angle)) * M_UNIT;

	// 이동할 수 있는 좌표인지 검증 후 최신화한다.
	if (!moveable(game, nx, ny))
		return ;
	game->pX = nx;
	game->pY = ny;
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
	if (key_code == KEY_UP || key_code == KEY_W)
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
