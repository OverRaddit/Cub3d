/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:50:11 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 18:28:54 by gshim            ###   ########.fr       */
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

	nx = g->px + (g->dirx * cos(angle) - g->diry * sin(angle)) * M_UNIT;
	ny = g->py + (g->dirx * sin(angle) + g->diry * cos(angle)) * M_UNIT;
	if (!moveable(g, nx, ny)
		|| !moveable(g, -nx + g->planex * 0.25, ny + g->planey * 0.25)
		|| !moveable(g, nx + g->planex * 0.25, ny + g->planey * 0.25)
		|| !moveable(g, -nx + g->planex * 0.25, ny - g->planey * 0.25)
		|| !moveable(g, nx + g->planex * 0.25, ny - g->planey * 0.25))
		return ;
	g->px = nx;
	g->py = ny;
}

void	rotate(t_game *g, double angle)
{
	double	tempx;
	double	tempy;

	tempx = g->dirx;
	tempy = g->diry;
	g->dirx = tempx * cos(angle) - tempy * sin(angle);
	g->diry = tempx * sin(angle) + tempy * cos(angle);
	tempx = g->planex;
	tempy = g->planey;
	g->planex = tempx * cos(angle) - tempy * sin(angle);
	g->planey = tempx * sin(angle) + tempy * cos(angle);
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
	else if (key_code == KEY_F)
		mousemode_toggle(game);
	return (0);
}
