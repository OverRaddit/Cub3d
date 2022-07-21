/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:56:18 by gshim             #+#    #+#             */
/*   Updated: 2022/07/21 18:14:18 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_event(t_game *g)
{
	int	mousex;
	int	mousey;

	mlx_mouse_get_pos(g->win, &mousex, &mousey);
	mlx_mouse_move(g->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	rotate(g, -(mousex - SCREEN_WIDTH / 2) * M_PI / 200);
}

void	mousemode_toggle(t_game *g)
{
	g->mousemode = !(g->mousemode);
	if (g->mousemode)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
}
