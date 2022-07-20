/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/20 21:10:46 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main_loop(t_game *g)
{
	int x;
	mlx_clear_window(g->mlx, g->win);

	unsigned int *screen = (unsigned int *)mlx_get_data_addr(g->screen.img, &(g->screen.bpp), &(g->screen.size_l), &(g->screen.endian));
	setScreen(g, screen);
	unsigned int *minimap = (unsigned int *)mlx_get_data_addr(g->minimap.img, &(g->minimap.bpp), &(g->minimap.size_l), &(g->minimap.endian));


	// Mouse logic
	int mouseX,mouseY;
	mlx_mouse_get_pos(g->win, &mouseX, &mouseY);
	mlx_mouse_move(g->win, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	rotate(g, -(mouseX - SCREEN_WIDTH/2) * M_PI/200);

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		// 초기값 설정
		ray_cal_init(g, x);
		getSideDist(g);

		// 광선이 부딪힌 지점 탐색
		DDA(g);

		// 닿은 거리로 세로줄의 길이정보 설정
		getDrawPoint(g);

		// 닿은 지점의 텍스쳐 설정
		t_texture wall_tex = getWallTexture(g);

		unsigned int *data = (unsigned int *)mlx_get_data_addr(wall_tex.texture.img, &(wall_tex.texture.bpp), &(wall_tex.texture.size_l), &(wall_tex.texture.endian));

		double wallX;
		int texWidth = wall_tex.width;
		int texHeight = wall_tex.height;

		if (g->side == 0) wallX = g->pY + g->perpWallDist * g->rayDirY;
		else           wallX = g->pX + g->perpWallDist * g->rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)texWidth);
		if(g->side == 0 && g->rayDirX > 0) texX = texWidth - texX - 1;
		if(g->side == 1 && g->rayDirY < 0) texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / g->lineHeight;
		// Starting texture coordinate
		double texPos = (g->drawStart - SCREEN_HEIGHT / 2 + g->lineHeight / 2) * step;



		for(int y = g->drawStart; y<g->drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			//Uint32 color = texture[texNum][texHeight * texY + texX];
			int color = data[texHeight * texY + texX];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if(g->side == 1) color = (color >> 1) & 8355711;

			//g->screen.data[y * SCREEN_WIDTH + x] = color;
			screen[y * SCREEN_WIDTH + x] = color;
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);


	// 미니맵 그리기
	paint_minimap(g, minimap);

	return (0);
}

// gshim's main
int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	game.map = &map;
	if (argc != 2){
		ft_putendl_fd("Error", 2);
		return 0;
	}
	ft_memset(&map, 0, sizeof(t_map));
	parse(&map, argv[1]);
	map_setting(&map);

	// 수동입력
	//game.map = &map;
	player_init(&game);


	window_init(&game);
	img_init(&game);

	mlx_mouse_hide();

	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_event, &map);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);

	free_all_data(&map);
	return 0;
}
