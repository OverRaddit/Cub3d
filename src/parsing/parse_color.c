/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:48:27 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/13 16:06:47 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*access_information(char *line)
{
	while (is_upper(*line) == TRUE)
		line++;
	while (is_space(*line) == TRUE)
		line++;
	return (line);
}

static int	parse_color_handler(char *line)
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
	while (line[++i] && ft_isdigit(line[i]))
		r = r * 10 + (line[i] - '0');
	while (line[++i] && ft_isdigit(line[i]))
		g = g * 10 + (line[i] - '0');
	while (line[++i] && ft_isdigit(line[i]))
		b = b * 10 + (line[i] - '0');
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("Invalid RGB Format");
	color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

int	parse_color(char *line)
{
	int		color;

	line = access_information(line);
	color = parse_color_handler(line);
	return (color);
}
