/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:57:49 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/17 19:23:07 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_possible_chars(char *possible_chars, char c)
{
	int	i;

	i = 0;
	while (possible_chars[i])
	{
		if (possible_chars[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	is_map_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (check_possible_chars("01NSEW ", line[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_valid_data(char *line)
{
	if ((int)ft_strlen(line) > 3)
	{
		if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			return (NO);
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
			return (SO);
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' )
			return (WE);
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
			return (EA);
		else if (line[0] == 'F' && line[1] == ' ')
			return (FLOOR);
		else if (line[0] == 'C' && line[1] == ' ')
			return (CEIL);
	}
	if (is_map_valid(line))
		return (MAP);
	return (ERROR);
}

static int	is_cub_file(char *cub_file_path)
{
	int	file_len;
	int	is_same;

	file_len = ft_strlen(cub_file_path);
	if (ft_strncmp(cub_file_path + file_len - 4, ".cub", 4) == 0)
		is_same = TRUE;
	else
		is_same = FALSE;
	return (is_same);
}

int	get_cub_file_fd(t_map *map, char *cub_file_path)
{
	int	fd;

	if (!is_cub_file(cub_file_path))
		exit_error(map, "Invalid File Extension");
	fd = open(cub_file_path, O_RDONLY);
	if (fd == -1)
		exit_error(map, "Cannot Open File");
	return (fd);
}
