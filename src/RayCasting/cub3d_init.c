/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:42 by gshim             #+#    #+#             */
/*   Updated: 2022/07/30 11:18:31 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *g)
{
	double	angle;

	g->px = g->map->player.px;
	g->py = g->map->player.py;
	if (g->map->player.starting_sight == 'N')
		angle = M_PI;
	else if (g->map->player.starting_sight == 'E')
		angle = M_PI_2;
	else if (g->map->player.starting_sight == 'S')
		angle = 0;
	else
		angle = -M_PI_2;
	g->dirx = cos(angle);
	g->diry = sin(angle);
	g->planex = 0.66 * cos(angle - M_PI_2);
	g->planey = 0.66 * sin(angle - M_PI_2);
	g->miniw = SCREEN_WIDTH * MINIMAP_SCALE;
	g->minih = SCREEN_HEIGHT * MINIMAP_SCALE;
	g->gridw = g->miniw / g->map->col;
	g->gridh = g->minih / g->map->row;
	g->mousemode = 0;
}

void	img_init(t_game *g)
{
	t_texture	*tx;

	tx = g->map->tex;
	tx[0].texture.img = mlx_xpm_file_to_image(g->mlx,
			tx[0].tex_path_malloc, &(tx[0].width), &(tx[0].height));
	tx[1].texture.img = mlx_xpm_file_to_image(g->mlx,
			tx[1].tex_path_malloc, &(tx[1].width), &(tx[1].height));
	tx[2].texture.img = mlx_xpm_file_to_image(g->mlx,
			tx[2].tex_path_malloc, &(tx[2].width), &(tx[2].height));
	tx[3].texture.img = mlx_xpm_file_to_image(g->mlx,
			tx[3].tex_path_malloc, &(tx[3].width), &(tx[3].height));
	g->screen.img = mlx_new_image(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	g->screen.data = (t_ui *)mlx_get_data_addr(g->screen.img,
			&(g->screen.bpp), &(g->screen.size_l), &(g->screen.endian));
	g->minimap.img = mlx_new_image(g->mlx, g->miniw, g->minih);
	g->minimap.data = (t_ui *)mlx_get_data_addr(g->minimap.img,
			&(g->minimap.bpp), &(g->minimap.size_l), &(g->minimap.endian));
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
	return (0);
}
