/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:18:19 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/14 20:44:57 by jinyoo           ###   ########.fr       */
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

#define LAST 0

#define NO_COLOR -1

typedef struct	s_texture
{
	char		*tex_path_malloc;
	int			*texture;
	double		width;
	double		height;
}	t_texture;

typedef struct	s_map
{
	t_texture	tex[4];
	int			floor_color;
	int			ceiling_color;
	char		*tmp_map_malloc;
	char		**map_malloc;
	int			row;
	int			col;
	char		starting_sight;
}	t_map;

// 플레이어 구조체에 초기 x,y

//error.c
void	exit_error(char *message);

//=================================parsing=====================================

//parse.c
void	parse(t_map *map, char *cub_file_path);

//validation.c
int	check_valid_data(char *line);
int	get_cub_file_fd(char *cub_file_path);

//parse_color.c
char	*access_information(char *line);
int	parse_color(char *line);

//parse_map.c
void	parse_map(t_map *map);
char	*save_tmp_map(char *s1, char *s2);
int	check_data_order(t_map *map);

//=============================================================================

// util.c
int	is_upper(char c);
int	is_space(char c);


//=============================================================================
// Gshim
//=============================================================================



#endif
