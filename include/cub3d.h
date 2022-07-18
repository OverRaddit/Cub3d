/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:18:19 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/18 00:08:23 by gshim            ###   ########.fr       */
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
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13

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

typedef struct	s_player
{
	double	px;
	double	py;
	double	dirx;
	double	diry;
	char	starting_sight;
}	t_player;

typedef struct	s_map
{
	t_player	player;
	t_texture	tex[4];
	int			floor_color;
	int			ceiling_color;
	char		*tmp_map_malloc;
	char		**map_malloc;
	int			row;
	int			col;
}	t_map;
// 14 *
//error.c
void	exit_error(t_map *map, char *message);
void	free_all_data(t_map *map);

//=================================parsing=====================================

//parse.c
void	parse(t_map *map, char *cub_file_path);
char	*access_information(char *line);

//validation.c
int	check_valid_data(char *line);
int	get_cub_file_fd(t_map *map,char *cub_file_path);

//parse_color.c
int	parse_color(t_map *map, char *line, int identifier);

//parse_map.c
void	parse_map(t_map *map);
char	*save_tmp_map(char *s1, char *s2);
int	check_data_order(t_map *map);

//setting.c
void	map_setting(t_map *map);

//=============================================================================

// util.c
int	is_upper(char c);
int	is_space(char c);


//=============================================================================
// Gshim
//=============================================================================

#define _USE_MATH_DEFINES
# include <math.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	// t_img	img;
	// t_img	tile;
	// t_img	item;
	//char		map[10][10];

	// player's Pos, Dir, cameraDir(right)
	double	pX;
	double	pY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	//t_raycasting r;
	t_map	*map;
}	t_game;

typedef struct s_raycasting
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}	t_raycasting;

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define M_UNIT			0.1		// 이동단위
# define R_UNIT			M_PI_4	// 회전단위
//# define R_UNIT			M_PI / 180	// 회전단위

// color
//# define RGB_Red 255*65536+255*256+255
# define RGB_Red 255*65536+0+0
# define RGB_Green 0*65536+255*256+0
# define RGB_Blue 0*65536+0*256+255
# define RGB_White 255*65536+255*256+255
# define RGB_Yellow 255*65536+255*256+0

void	window_init(t_game *game);
void	move(t_game *game, double angle);
void	rotate(t_game *game, double angle);
int		deal_key(int key_code, t_game *game);


#endif
