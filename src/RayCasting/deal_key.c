/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 13:30:40 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	moveable(t_game *game, double nx, double ny)
{
	int	x;
	int	y;

	x = (int)nx;
	y = (int)ny;
	if (x < 0 || y < 0 || x >= game->map->row || y >= game->map->col)
		return (1);
	if (game->map->map_malloc[x][y] > '0')
		return (0);
	else
		return (1);
}

void	move(t_game *g, double angle)
{
	double	nx;
	double	ny;

	nx = g->pX + (g->dirX * cos(angle) - g->dirY * sin(angle)) * M_UNIT;
	ny = g->pY + (g->dirX * sin(angle) + g->dirY * cos(angle)) * M_UNIT;
	if (!moveable(g, nx, ny)
		|| !moveable(g, -nx + g->planeX * 0.25, ny + g->planeY * 0.25)
		|| !moveable(g, nx + g->planeX * 0.25, ny + g->planeY * 0.25)
		|| !moveable(g, -nx + g->planeX * 0.25, ny - g->planeY * 0.25)
		|| !moveable(g, nx + g->planeX * 0.25, ny - g->planeY * 0.25))
		return ;
	g->pX = nx;
	g->pY = ny;
}

void	rotate(t_game *g, double angle)
{
	double	tempX;
	double	tempY;

	tempX = g->dirX;
	tempY = g->dirY;
	g->dirX = tempX * cos(angle) - tempY * sin(angle);
	g->dirY = tempX * sin(angle) + tempY * cos(angle);
	tempX = g->planeX;
	tempY = g->planeY;
	g->planeX = tempX * cos(angle) - tempY * sin(angle);
	g->planeY = tempX * sin(angle) + tempY * cos(angle);
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_event(game->map);
	else if (key_code == KEY_UP || key_code == KEY_W)
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
	return (0);
}
