/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:42 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 13:20:18 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_game *g)
{
	double	angle;

	g->pX = g->map->player.px;
	g->pY = g->map->player.py;
	if (g->map->player.starting_sight == 'N')
		angle = M_PI;
	else if (g->map->player.starting_sight == 'E')
		angle = M_PI_2;
	else if (g->map->player.starting_sight == 'S')
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
}

void	img_init(t_game *game)
{
	t_texture	*tx;

	tx = game->map->tex;
	tx[0].texture.img = mlx_xpm_file_to_image(game->mlx,
			tx[0].tex_path_malloc, &(tx[0].width), &(tx[0].height));
	tx[1].texture.img = mlx_xpm_file_to_image(game->mlx,
			tx[1].tex_path_malloc, &(tx[1].width), &(tx[1].height));
	tx[2].texture.img = mlx_xpm_file_to_image(game->mlx,
			tx[2].tex_path_malloc, &(tx[2].width), &(tx[2].height));
	tx[3].texture.img = mlx_xpm_file_to_image(game->mlx,
			tx[3].tex_path_malloc, &(tx[3].width), &(tx[3].height));
	game->screen.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->minimap.img = mlx_new_image(game->mlx, game->miniW, game->miniH);
}

int	window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, (int)SCREEN_WIDTH,
			(int)SCREEN_HEIGHT, "CUB_3D");
	if (!game->win)
		return (1);
}
