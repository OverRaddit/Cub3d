/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:02 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/12 22:19:07 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*update_map(char *s1, char *s2)
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

static int	save_data(t_map *map, int g_ret, int identifier, char *line)
{
	char	*tex_path;

	if (identifier >= NO && identifier <= EA)
	{
		if (map->tex[identifier].tex_path)
			exit_error("Duplicated Identifier");
		tex_path = access_information(line);
		map->tex[identifier].tex_path = tex_path;
	}
	else if (identifier == CEIL || identifier == FLOOR)
	{
		if (identifier == CEIL)
			map->ceiling_color = parse_color(line);
		else
			map->floor_color = parse_color(line);
	}
	//맵 저장
	else
	{
		map->tmp_map_malloc = update_map(map->tmp_map_malloc, line);
		if (g_ret == 0 && parse_map(map) == ERROR)
			return (free_memory_return(line, ERROR));
	}
	return SUCCESS;
}

int	parse(t_map *map, const char *cub_file_path)
{
	int		fd;
	char	*line;
	int		identifier;

	if (!is_cub_file(cub_file_path))
		exit_error("Invalid File Extension");
	fd = open(cub_file_path, O_RDONLY);
	if (fd == -1)
		exit_error("Cannot Open File");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			continue ;
		identifier = check_valid_data(line);
		if (identifier == ERROR)
			exit_error("Invalid Identifier");
		if (save_data(map, 1, identifier, line) == ERROR)
			return (ERROR);
		free(line);
	}
	save_data(map, 0, identifier, line);
	close(fd);
	free(line);
	return (SUCCESS);
}
