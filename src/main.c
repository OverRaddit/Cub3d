/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/16 15:34:35 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_memset(&map, 0, sizeof(t_map));
		parse(&map, argv[1]);
		for (int i = 0;i < 4;i++)
			printf("tex_path : %s\n", map.tex[i].tex_path);
		printf("\n");
		printf("ceilling color: %#x\n", map.ceiling_color);
		printf("floor color: %#x\n", map.floor_color);
		int y = -1;
		while (map.map[++y])
		{
			int x = -1;
			while (map.map[y][++x])
				printf("%c", map.map[y][x]);
			printf("\n");
		}
	}
	return 0;
}

int main_loop(t_game *g)
{
	printf("main_loop()\n");

	for(int x = 0; x < SCREEN_WIDTH; x++)
	{
		// Declaration
		double cameraX = 2 * x / (double)(SCREEN_WIDTH-1) - 1;		// ?? 분모는 w가 아니라 w-1아닌가?
		double rayDirX = g->dirX + g->planeX * cameraX;
		double rayDirY = g->dirY + g->planeY * cameraX;

		int mapX = (int)(g->pX);
		int mapY = (int)(g->pY);

		double sideDistX,sideDistY;

		double deltaDistX = fabs(1 / rayDirX);	// double용 절댓값함수
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX,stepY;
		int hit=0,side;

		// calculate
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (g->pX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - g->pX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (g->pY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - g->pY) * deltaDistY;
		}

		// perform DDA
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
			if (g->map[mapX][mapY] > 0) hit = 1;
		}

		// 카메라평면~부딫친벽과의 거리
		if (side == 0)
			perpWallDist = (mapX - g->pX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - g->pY + (1 - stepY) / 2) / rayDirY;

		// 그릴 지점 찾기.
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

		// =========================================
		// 여기부터 아직 이해 ㄴㄴ
		// =========================================
		int color;
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
		verLine(x, drawStart, drawEnd, color);
	}

	return (0);
}

// gshim's main
// int	main(int argc, char *argv[])
// {
// 	t_map	map;

// 	if (argc != 2)
// 		ft_putendl_fd("Error", 2);
// 	else
// 	{
// 		ft_memset(&map, 0, sizeof(t_map));
// 		parse(&map, argv[1]);
// 		map_setting(&map);
// 		// for (int i = 0;i < 4;i++)
// 		// 	printf("tex_path : %s\n", map.tex[i].tex_path_malloc);
// 		// printf("\n");
// 		// printf("ceilling color: %#x\n", map.ceiling_color);
// 		// printf("floor color: %#x\n", map.floor_color);
// 		// printf("col : %d, row : %d\n", map.col, map.row);
// 		// printf("Starting Sight : %c\n", map.player.starting_sight);
// 		// printf("px : %d, py : %d\n", map.player.px, map.player.py);
// 		// int y = -1;
// 		// while (map.map_malloc[++y])
// 		// {
// 		// 	int x = -1;
// 		// 	while (map.map_malloc[y][++x])
// 		// 		printf("%c", map.map_malloc[y][x]);
// 		// 	printf("\n");
// 		// }
// 	}

// 	window_init(&game);
// 	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
// 	//mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &closed, &game);
// 	mlx_loop_hook(game.mlx, &main_loop, &game);	// 아무 이벤트도 없는경우.
// 	mlx_loop(game.mlx);							//

// 	return 0;
// }
