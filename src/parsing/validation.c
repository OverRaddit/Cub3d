/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:57:49 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/12 17:00:06 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_possible_chars(char *possible_chars, char c)
{
	int	i;

	i = 0;
	while (possible_chars[i])
	{
		if (possible_chars[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
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
	if (line[0] == 'N' && line[1] == 'O')
		return (NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (EA);
	else if (line[0] == 'F' && line[1] == ' ')
		return (FLOOR);
	else if (line[0] == 'C' && line[1] == ' ')
		return (CEIL);
	else if (is_map_valid(line))
		return (MAP);
	return (ERROR);
}

int	is_cub_file(const char *cub_file_path)
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
