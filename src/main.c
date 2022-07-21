/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/20 01:20:05 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main_loop(t_game *g)
{
	int x;
	unsigned int *screen;

	mlx_clear_window(g->mlx, g->win);
	screen = (unsigned int *)mlx_get_data_addr(g->screen.img, &(g->screen.bpp), &(g->screen.size_l), &(g->screen.endian));
	setScreen(g, screen);
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
		cal_texture(g, wall_tex);
		// draw Line
		drawLine(g, wall_tex, data, screen, x);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	return (0);
}

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

	player_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_event, &map);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);

	free_all_data(&map);
	return 0;
}
