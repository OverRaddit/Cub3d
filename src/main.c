/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/17 20:02:09 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
// {
// 	t_map	map;

// 	if (argc != 2)
// 		ft_putendl_fd("Error", 2);
// 	else
// 	{
// 		ft_memset(&map, 0, sizeof(t_map));
// 		parse(&map, argv[1]);
// 		for (int i = 0;i < 4;i++)
// 			printf("tex_path : %s\n", map.tex[i].tex_path);
// 		printf("\n");
// 		printf("ceilling color: %#x\n", map.ceiling_color);
// 		printf("floor color: %#x\n", map.floor_color);
// 		int y = -1;
// 		while (map.map[++y])
// 		{
// 			int x = -1;
// 			while (map.map[y][++x])
// 				printf("%c", map.map[y][x]);
// 			printf("\n");
// 		}
// 	}
// 	return 0;
// }

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main_loop(t_game *g)
{
	//t_raycasting ray;
	// 이전 화면을 지운다.
	mlx_clear_window(g->mlx, g->win);
	printf("pos(%f, %f), dir(%f, %f => %f degree), plane(%f, %f)\n", g->pX, g->pY, g->dirX, g->dirY, g->dirY/g->dirX, g->planeX, g->planeY);

	for(int x = 0; x < SCREEN_WIDTH; x++)
	{
		// Declaration
		double cameraX = 2 * x / (double)(SCREEN_WIDTH-1) - 1;		// ?? 분모는 w가 아니라 w-1아닌가?
		//double cameraX = 2 * x / (double)(SCREEN_WIDTH) - 1;		// ?? 분모는 w가 아니라 w-1아닌가?
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
			if (worldMap[mapX][mapY] > 0) hit = 1;
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

//======================
// Untextured Version
//======================
		// int color;
		// switch(worldMap[mapX][mapY])
		// {
		// 	case 1:  color = RGB_Red;    break; //red
		// 	case 2:  color = RGB_Green;  break; //green
		// 	case 3:  color = RGB_Blue;   break; //blue
		// 	case 4:  color = RGB_White;  break; //white
		// 	default: color = RGB_Yellow; break; //yellow
		// }

		// //give x and y sides different brightness
		// if(side == 1) {color = color / 2;}

		// //draw the pixels of the stripe as a vertical line
		// for(int i=drawStart;i<=drawEnd;i++)
		// 	mlx_pixel_put(g->mlx, g->win, x, i, color);

//======================
// Textured Version
//======================
		double wallX;
		if (side == 0) wallX = g->pY + perpWallDist * rayDirY;
		else           wallX = g->pX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)texWidth);
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
	}

	double step = 1.0 * texHeight / lineHeight;
	// Starting texture coordinate
	double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
	for(int y = drawStart; y<drawEnd; y++)
	{
	// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
	int texY = (int)texPos & (texHeight - 1);
	texPos += step;
	Uint32 color = texture[texNum][texHeight * texY + texX];
	//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
	if(side == 1) color = (color >> 1) & 8355711;
	buffer[y][x] = color;

	return (0);
}

// gshim's main
int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_memset(&map, 0, sizeof(t_map));
		parse(&map, argv[1]);
		map_setting(&map);
		// for (int i = 0;i < 4;i++)
		// 	printf("tex_path : %s\n", map.tex[i].tex_path_malloc);
		// printf("\n");
		// printf("ceilling color: %#x\n", map.ceiling_color);
		// printf("floor color: %#x\n", map.floor_color);
		// printf("col : %d, row : %d\n", map.col, map.row);
		// printf("Starting Sight : %c\n", map.player.starting_sight);
		// printf("px : %d, py : %d\n", map.player.px, map.player.py);
		// int y = -1;
		// while (map.map_malloc[++y])
		// {
		// 	int x = -1;
		// 	while (map.map_malloc[y][++x])
		// 		printf("%c", map.map_malloc[y][x]);
		// 	printf("\n");
		// }
	}

	// 수동입력
	game.pX = 6;
	game.pY = 5;
	game.dirX = -1;
	game.dirY = 0;
	game.planeX = 0;
	game.planeY = 0.66;

	window_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	//mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &closed, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);	// 아무 이벤트도 없는경우.
	mlx_loop(game.mlx);							//

	return 0;
}
