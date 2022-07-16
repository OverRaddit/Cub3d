/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/15 12:38:14 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=========================
// 현재 사용하는 map은 임시 더미맵이다. 파싱한 맵이 아니다.
//=========================
static int moveable(t_game *game, double nx, double ny)
{
	if (game->map[(int)ny][(int)nx] > 0)
		return 0;
	else
		return 1;
}

void	move(t_game *game, double angle)
{
	double nx,ny;

	// 이동할 좌표를 구한다.
	nx = game->pX + (game->dirX * cos(angle) - game->dirY * sin(angle)) * M_UNIT;
	ny = game->pY + (game->dirX * sin(angle) + game->dirY * cos(angle)) * M_UNIT;

	// 이동할 수 있는 좌표인지 검증 후 최신화한다.
	if (!moveable(game, nx, ny))
		return ;
	game->pX = nx;
	game->pY = ny;
}

void	rotate(t_game *game, double angle)
{
	// 플레이어의 방향벡터를 최신화한다.
	game->dirX += game->dirX * cos(angle) - game->dirY * sin(angle);
	game->dirY += game->dirX * sin(angle) - game->dirY * cos(angle);

	// 카메라 평면을 어떻게.....?
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
	printf("Key Event\n");
	return (0);
}
