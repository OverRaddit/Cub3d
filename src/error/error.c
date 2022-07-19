/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:17:52 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/19 16:23:27 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_all_data(t_map *map)
{
	int	i;

	if (map->tmp_map_malloc)
		free(map->tmp_map_malloc);
	map->tmp_map_malloc = NULL;
	if (map->map_malloc)
	{
		i = -1;
		while (map->map_malloc[++i])
		{
			free(map->map_malloc[i]);
			map->map_malloc[i] = NULL;
		}
		free(map->map_malloc);
	}
	i = -1;
	while (++i < 4)
	{
		if (map->tex[i].tex_path_malloc)
		{
			free(map->tex[i].tex_path_malloc);
			map->tex[i].tex_path_malloc = NULL;
		}
	}
}

int		exit_event(t_map *map)
{
	ft_putendl_fd("EXIT CUB3D", 0);
	free_all_data(map);
	exit(1);
}

void	exit_error(t_map *map, char *message)
{
	ft_putendl_fd("ERROR", 2);
	if (message)
		ft_putendl_fd(message, 2);
	free_all_data(map);
	exit(1);
}
