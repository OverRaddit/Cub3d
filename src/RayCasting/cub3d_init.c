/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:09:42 by gshim             #+#    #+#             */
/*   Updated: 2022/07/17 21:40:09 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (int)SCREEN_WIDTH,
			(int)SCREEN_HEIGHT, "CUB_3D");

	// 각 mlx 함수에 대한 오류처리 로직 필요
}
