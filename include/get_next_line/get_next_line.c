/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 23:22:58 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/11 21:28:17 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline_idx(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	get_one_line(char **backup, char **line, int newline_idx)
{
	char	*tmp;

	(*backup)[newline_idx] = '\0';
	*line = gnl_strdup(*backup);
	if (gnl_strlen(*backup + newline_idx + 1) == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = gnl_strdup(*backup + newline_idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

static int	get_last_line(char **backup, char **line, int size)
{
	int	newline_idx;

	if (size < -1)
		return (-1);
	newline_idx = get_newline_idx(*backup);
	if (*backup && newline_idx >= 0)
		return (get_one_line(backup, line, newline_idx));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = gnl_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			newline_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!backup[fd])
		backup[fd] = gnl_strdup("");
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		backup[fd] = gnl_strjoin(backup[fd], buf);
		newline_idx = get_newline_idx(backup[fd]);
		if (newline_idx >= 0)
			return (get_one_line(&backup[fd], line, newline_idx));
		size = read(fd, buf, BUFFER_SIZE);
	}
	if (size < 0)
	{
		free(backup[fd]);
		return (-1);
	}
	return (get_last_line(&backup[fd], line, size));
}
