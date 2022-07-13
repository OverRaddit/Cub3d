/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:02 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/13 18:30:32 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	parse_map(t_map *map)
{
	// int row;
	// int col;

	map->map = ft_split(map->tmp_map_malloc, '\n');
	if(map->map == NULL)
		exit_error(NULL);
	// row = -1;
	// col = 0;
	// while (map->map[++row] != NULL)
	// 	if ((int)ft_strlen(map->map[row]) > col)
	// 		col = (int)ft_strlen(map->map[row]);
	// map->row = row;
	// map->col = col;
	free(map->tmp_map_malloc);
	map->tmp_map_malloc = NULL;
}

static char	*save_map(char *s1, char *s2)
{
	char	*temp;
	char	*result;

	if (s1 == NULL)
		s1 = ft_strdup("");
	temp = ft_strjoin(s1, "\n");
	result = ft_strjoin(temp, s2);
	free(s1);
	free(temp);
	return (result);
}

static void	save_data(t_map *map, int g_ret, int identifier, char *line)
{
	char	*tex_path;

	if (identifier >= NO && identifier <= EA)
	{
		if (map->tex[identifier].tex_path)
			exit_error("Duplicated Identifier");
		tex_path = access_information(line);
		map->tex[identifier].tex_path = ft_strdup(tex_path);
	}
	else if (identifier == CEIL || identifier == FLOOR)
	{
		if (identifier == CEIL)
			map->ceiling_color = parse_color(line);
		else
			map->floor_color = parse_color(line);
	}
	else
	{
		map->tmp_map_malloc = save_map(map->tmp_map_malloc, line);
		if (g_ret == 0)
			parse_map(map);
	}
}

static int	get_cub_file_fd(char *cub_file_path)
{
	int		fd;

	if (!is_cub_file(cub_file_path))
		exit_error("Invalid File Extension");
	fd = open(cub_file_path, O_RDONLY);
	if (fd == -1)
		exit_error("Cannot Open File");
	return fd;
}

void	parse(t_map *map, char *cub_file_path)
{
	int		fd;
	int		gnl_ret;
	char	*line;
	int		identifier;

	fd = get_cub_file_fd(cub_file_path);
	gnl_ret = get_next_line(fd, &line);
	while (gnl_ret > 0)
	{
		if (line[0] != '\0')
		{
			identifier = check_valid_data(line);
			if (identifier == ERROR)
				exit_error("Unacceptable Data Founded");
			save_data(map, gnl_ret, identifier, line);
		}
		free(line);
		line = NULL;
		gnl_ret = get_next_line(fd, &line);
	}
	if (gnl_ret != ERROR)
		save_data(map, gnl_ret, identifier, line);
	close(fd);
	free(line);
}
