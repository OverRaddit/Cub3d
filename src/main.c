/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:50:46 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/30 15:07:59 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main_loop(t_game *g)
{
	int	x;

	mlx_clear_window(g->mlx, g->win);
	setscreen(g);
	if (g->mousemode)
		mouse_event(g);
	if (g->w || g->a || g->s || g->d)
		move_event(g);
	if (g->l || g->r)
		rotation_event(g);
	x = -1;
	while (++x < SCREEN_WIDTH)
		cast_one_ray(g, x);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	paint_minimap(g);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	ft_memset((void *)&game, 0, sizeof(t_game));
	game.map = &map;
	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_memset(&map, 0, sizeof(t_map));
	parse(&map, argv[1]);
	map_setting(&map);
	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_DOWN, 0, &e_keydown, &game);
	mlx_hook(game.win, X_EVENT_KEY_UP, 0, &e_keyup, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_event, &map);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
