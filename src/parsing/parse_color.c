/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:48:27 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/17 19:25:21 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_color_data(t_map *map, char *line)
{
	char	**color_data_malloc;
	int		i;
	int		j;

	color_data_malloc = ft_split(line, ',');
	if (!color_data_malloc)
		exit_error(map, "Invalid RGB Format");
	i = -1;
	while (color_data_malloc[++i])
	{
		j = -1;
		while (color_data_malloc[i][++j])
			if (!ft_isdigit(color_data_malloc[i][j]))
				exit_error(map, "Invalid RGB Format");
	}
	if (i != 3)
		exit_error(map, "Invalid RGB Format");
	i = -1;
	while (color_data_malloc[++i])
		free(color_data_malloc[i]);
	free(color_data_malloc);
}

static int	parse_color_handler(t_map *map, char *line)
{
	int	i;
	int	r;
	int	g;
	int	b;
	int	color;

	i = -1;
	r = 0;
	g = 0;
	b = 0;
	check_color_data(map, line);
	while (line[++i] && ft_isdigit(line[i]))
		r = r * 10 + (line[i] - '0');
	while (line[++i] && ft_isdigit(line[i]))
		g = g * 10 + (line[i] - '0');
	while (line[++i] && ft_isdigit(line[i]))
		b = b * 10 + (line[i] - '0');
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(map, "Invalid RGB Format");
	color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

int	parse_color(t_map *map, char *line, int identifier)
{
	int		color;

	if (line[0] == '\0')
		exit_error(map, "Invalid Map");
	if ((identifier == FLOOR && map->floor_color != NO_COLOR) || \
		(identifier == CEIL && map->ceiling_color != NO_COLOR))
		exit_error(map, "Duplicated Identifier");
	line = access_information(line);
	color = parse_color_handler(map, line);
	return (color);
}
