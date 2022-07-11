/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/11 21:50:50 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_game *game, int x2, int y2)
{
	if (game->map[y2][x2] == '1')
		return ;
	else if (game->map[y2][x2] == 'C')
	{
		game->map[y2][x2] = '0';
		game->point++;
	}
	else if (game->map[y2][x2] == 'E' && game->point == game->goal)
		closed(1);
	if (game->map[game->pos_y][game->pos_x] == '0' ||
			game->map[game->pos_y][game->pos_x] == 'C')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->tile.img,
			0 * 32, 0 * 32, 32, 32,
			game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	else if (game->map[game->pos_y][game->pos_x] == 'E')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->item.img,
			5 + 5 * 20, 5 + 5 * 20, 18, 18,
			game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	game->pos_x = x2;
	game->pos_y = y2;
	game->cnt++;
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		closed(3);
	if (key_code == KEY_UP || key_code == KEY_W)
		move(game, game->pos_x, game->pos_y - 1);
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		move(game, game->pos_x, game->pos_y + 1);
	else if (key_code == KEY_LEFT || key_code == KEY_A)
		move(game, game->pos_x - 1, game->pos_y);
	else if (key_code == KEY_RIGHT || key_code == KEY_S)
		move(game, game->pos_x + 1, game->pos_y);
	mlx_put_image_to_window_scale(game->mlx, game->win, game->img.img,
		1 * 32, 4 * 32, 32, 32,
		game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	print_status(game);
	return (0);
}