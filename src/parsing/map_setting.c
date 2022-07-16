/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:13:44 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/15 17:35:29 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	save_player_position(t_map *map, int x, int y)
{
	if (map->player.starting_sight || map->player.px || map->player.py)
		exit_error("Invalid Map");
	map->player.starting_sight = map->map_malloc[y][x];
	map->player.px = x;
	map->player.py = y;
}

static int	setting_handler(t_map *map, int x, int y)
{
	if (x == 0 || x == (int)ft_strlen(map->map_malloc[y]) || \
	y == 0 || y == map->row - 1)
		return (ERROR);
	if (map->map_malloc[y][x + 1] == ' ' || map->map_malloc[y][x - 1] == ' ')
		return (ERROR);
	if ((int)ft_strlen(map->map_malloc[y - 1]) <= x \
	|| map->map_malloc[y - 1][x] == ' ' || map->map_malloc[y - 1][x] == '\0')
		return (ERROR);
	if ((int)ft_strlen(map->map_malloc[y + 1]) <= x \
	|| map->map_malloc[y + 1][x] == ' ' || map->map_malloc[y + 1][x] == '\0')
		return (ERROR);
	if (map->map_malloc[y][x] != '0')
		save_player_position(map, x, y);
	return (SUCCESS);
}

void	map_setting(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map_malloc[++y])
	{
		x = -1;
		while (map->map_malloc[y][++x])
		{
			if (ft_strchr("1 ", map->map_malloc[y][x]) != NULL)
				continue ;
			else if (ft_strchr("0NSEW", map->map_malloc[y][x]) != NULL)
			{
				if (setting_handler(map, x, y) == ERROR)
					exit_error("Invalid Map");
			}
		}
	}
	if (!map->player.starting_sight)
		exit_error("Invalid Map");
}
