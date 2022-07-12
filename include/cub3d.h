/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:18:19 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/12 20:49:52 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

# define ERROR -1
# define SUCCESS 1

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define FLOOR 4
# define CEIL 5
# define MAP 6

# define FALSE 0
# define TRUE 1

typedef struct	s_texture
{
	char		*tex_path;
	int			*texture;
	double		width;
	double		height;
}	t_texture;

typedef struct	s_map
{
	t_texture	tex[4];
	int			floor_color;
	int			ceiling_color;
	char		*temp_map;
	char		**map;
	int			row;
	int			col;
}	t_map;

//error.c
void	exit_error(char *message);

//parse.c
int	parse(t_map *map, const char *cub_file_path);

//validation.c
int	is_cub_file(const char *cub_file_path);
int	check_valid_data(char *line);

//parse_color.c
char	*access_information(char *line);
int	parse_color(char *line);

// util.c
int	is_upper(char c);
int	is_space(char c);

//=============================================================================
// Gshim
//=============================================================================



#endif
