/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:42 by gshim             #+#    #+#             */
/*   Updated: 2022/07/19 03:40:07 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_init(t_game *g)
{
	char c = g->map->player.starting_sight;
	double angle;
	g->pX = g->map->player.px;
	g->pY = g->map->player.py;

	//"NSWE"
	// 이 부분을 문자열의 인덱스를통해 아름답게 만들고 싶다.
	if (c == 'N')
		angle = M_PI;
	else if (c == 'E')
		angle = M_PI_2;
	else if (c == 'S')
		angle = 0;
	else
		angle = -M_PI_2;

	g->dirX = cos(angle);
	g->dirY = sin(angle);
	g->planeX = 0.66 * cos(angle - M_PI_2);
	g->planeY = 0.66 * sin(angle - M_PI_2);
	//printf("~dir(%f, %f) plane(%f, %f)\n", g->dirX, g->dirY, g->planeX, g->planeY);
}

void	img_init(t_game *game)
{
	int	img_width;
	int	img_height;

	// 벽파일 열기
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"./texture/diamond_ore.xpm", &img_width, &img_height);
	//printf("%d %d\n", img_width, img_height);
	game->item.img = mlx_xpm_file_to_image(game->mlx,
			"./texture/gold_ore.xpm", &img_width, &img_height);
	//printf("%d %d\n", img_width, img_height);

	// 스크린 화면 생성
	game->screen.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (int)SCREEN_WIDTH,
			(int)SCREEN_HEIGHT, "CUB_3D");

	// 각 mlx 함수에 대한 오류처리 로직 필요
}
