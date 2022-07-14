/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:02 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/14 20:45:11 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	save_data(t_map *map, int is_last, int identifier, char *line)
{
	char	*tex_path;

	if (identifier >= NO && identifier <= EA)
	{
		if (map->tex[identifier].tex_path_malloc)
			exit_error("Duplicated Identifier");
		tex_path = access_information(line);
		map->tex[identifier].tex_path_malloc = ft_strdup(tex_path);
	}
	else if (identifier == CEIL)
		map->ceiling_color = parse_color(line);
	else if (identifier == FLOOR)
		map->floor_color = parse_color(line);
	else
	{
		if (check_data_order(map) == SUCCESS)
			map->tmp_map_malloc = save_tmp_map(map->tmp_map_malloc, line);
		if (is_last)
			parse_map(map);
	}
}

void	parse(t_map *map, char *cub_file_path)
{
	int		fd;
	char	*line;
	int		identifier;

	map->ceiling_color = NO_COLOR;
	map->floor_color = NO_COLOR;
	fd = get_cub_file_fd(cub_file_path);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			identifier = check_valid_data(line);
			if (identifier == ERROR)
				exit_error("Invalid Data Founded");
			save_data(map, FALSE, identifier, line);
		}
		free(line);
	}
	save_data(map, TRUE, identifier, line);
	close(fd);
	free(line);
}
