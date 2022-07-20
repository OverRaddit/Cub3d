/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:42 by gshim             #+#    #+#             */
/*   Updated: 2022/07/20 19:51:01 by gshim            ###   ########.fr       */
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

	g->miniW = SCREEN_WIDTH * MINIMAP_SCALE;
	g->miniH = SCREEN_HEIGHT * MINIMAP_SCALE;
	g->gridW = g->miniW / g->map->col;
	g->gridH = g->miniH / g->map->row;
	printf("map w,h = %d, %d\n", g->map->col, g->map->row);
	printf("minimap w,h = %d,%d\n", g->miniW, g->miniH);
	printf("grid w,h = %d,%d\n", g->gridW, g->gridH);
}

void	img_init(t_game *game)
{
	// 벽파일 열기
	printf("%s\n", game->map->tex[0].tex_path_malloc);
	printf("%s\n", game->map->tex[1].tex_path_malloc);
	printf("%s\n", game->map->tex[2].tex_path_malloc);
	printf("%s\n", game->map->tex[3].tex_path_malloc);
	game->map->tex[0].texture.img = mlx_xpm_file_to_image(game->mlx,
			game->map->tex[0].tex_path_malloc, &(game->map->tex[0].width), &(game->map->tex[0].height));
	game->map->tex[1].texture.img = mlx_xpm_file_to_image(game->mlx,
			game->map->tex[1].tex_path_malloc, &(game->map->tex[1].width), &(game->map->tex[1].height));
	game->map->tex[2].texture.img = mlx_xpm_file_to_image(game->mlx,
			game->map->tex[2].tex_path_malloc, &(game->map->tex[2].width), &(game->map->tex[2].height));
	game->map->tex[3].texture.img = mlx_xpm_file_to_image(game->mlx,
			game->map->tex[3].tex_path_malloc, &(game->map->tex[3].width), &(game->map->tex[3].height));

	printf("tex[0] : %p\n", game->map->tex[0].texture.img);
	printf("tex[1] : %p\n", game->map->tex[1].texture.img);
	printf("tex[2] : %p\n", game->map->tex[2].texture.img);
	printf("tex[3] : %p\n", game->map->tex[3].texture.img);

	// 스크린 화면 생성
	game->screen.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// 미니맵 화면 생성
	game->minimap.img = mlx_new_image(game->mlx, game->miniW, game->miniH);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (int)SCREEN_WIDTH,
			(int)SCREEN_HEIGHT, "CUB_3D");

	// 각 mlx 함수에 대한 오류처리 로직 필요
}
