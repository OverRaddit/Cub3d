/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:33:59 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/17 19:22:33 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_map(t_map *map)
{
	int	row;
	int	col;

	map->map_malloc = ft_split(map->tmp_map_malloc, '\n');
	if (map->map_malloc == NULL)
		exit_error(map, NULL);
	row = -1;
	col = 0;
	while (map->map_malloc[++row] != NULL)
		if ((int)ft_strlen(map->map_malloc[row]) > col)
			col = (int)ft_strlen(map->map_malloc[row]);
	map->row = row;
	map->col = col;
	free(map->tmp_map_malloc);
	map->tmp_map_malloc = NULL;
}

char	*save_tmp_map(char *s1, char *s2)
{
	char	*temp;
	char	*result;

	if (s1 == NULL)
		temp = ft_strdup("");
	else
		temp = ft_strjoin(s1, "\n");
	result = ft_strjoin(temp, s2);
	free(s1);
	free(temp);
	return (result);
}

int	check_data_order(t_map *map)
{
	int	i;

	if (map->tmp_map_malloc == NULL)
	{
		i = -1;
		while (++i < 4)
		{
			if (map->tex[i].tex_path_malloc == NULL)
				exit_error(map, "Invalid Data Order");
		}
		if (map->ceiling_color == NO_COLOR || map->floor_color == NO_COLOR)
			exit_error(map, "Invalid Data Order");
		if (map->ceiling_color == map->floor_color)
			exit_error(map, "Cannot Be Same Color");
	}
	return (SUCCESS);
}
