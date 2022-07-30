/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:18:19 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/30 15:11:08 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <string.h> // memset

# define X_EVENT_KEY_DOWN	2
# define X_EVENT_KEY_UP		3
# define X_EVENT_KEY_EXIT	17

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_F			3

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

# define LAST 0
# define NO_COLOR -1
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define MINIMAP_SCALE	0.25
# define M_UNIT			0.1		// 이동단위
# define R_UNIT			0.1		//M_PI_4	// 회전단위
# define BODY_UNIT		0.1		// 벽과 플레이어와의 최소거리

# define RGB_RED 16711680 // 255*65536+0+0
# define RGB_GREEN 65280 // 0*65536+255*256+0
# define RGB_BLUE 255 // 0*65536+0*256+255
# define RGB_WHITE 16777215 // 255*65536+255*256+255
# define RGB_YELLOW 16776960 // 255*65536+255*256+0

typedef unsigned int	t_ui;

typedef struct s_img
{
	void			*img;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct s_player
{
	double	px;
	double	py;
	double	dirx;
	double	diry;
	char	starting_sight;
}	t_player;

typedef struct s_texture
{
	char			*tex_path_malloc;
	unsigned int	*data;
	t_img			texture;
	int				width;
	int				height;
}	t_texture;

typedef struct s_map
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	wall;
	t_img	screen;
	t_img	minimap;
	t_map	*map;

	int		mousemode;
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l;
	bool	r;

	double	px;
	double	py;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;

	double	wallx;
	int		texx;
	int		texy;

	double	step;
	double	texpos;
	int		miniw;
	int		minih;
	int		gridw;
	int		gridh;
}	t_game;

//error.c
int			exit_event(t_map *map);
void		exit_error(t_map *map, char *message);
void		free_all_data(t_map *map);

//=================================parsing=====================================

//parse.c
void		parse(t_map *map, char *cub_file_path);
char		*access_information(char *line);

//validation.c
int			check_valid_data(char *line);
int			get_cub_file_fd(t_map *map, char *cub_file_path);

//parse_color.c
int			parse_color(t_map *map, char *line, int identifier);

//parse_map.c
void		parse_map(t_map *map);
char		*save_tmp_map(char *s1, char *s2);
int			check_data_order(t_map *map);

//setting.c
void		map_setting(t_map *map);

// util.c
int			is_upper(char c);
int			is_space(char c);

//=============================================================================
// Gshim
//=============================================================================

// cub3d_init.c
void		game_init(t_game *g);
void		img_init(t_game *game);
int			window_init(t_game *game);

// deal_key.c
void		move(t_game *game, double angle);
void		rotate(t_game *game, double angle);
int			e_keydown(int key_code, t_game *game);
int			e_keyup(int key_code, t_game *game);

// ray_cal.c
void		ray_cal_init(t_game *g, int x);
void		getsidedist(t_game *g);
void		dda(t_game *g);
void		getdrawpoint(t_game *g);
void		cal_texture(t_game *g, t_texture *wall_tex);

// ray_render.c
void		cast_one_ray(t_game *g, int x);
void		drawline(t_game *g, t_texture *wall_tex, int x);
void		setscreen(t_game *g);
t_texture	getwalltexture(t_game *g);

// minimap.c
void		paint_minimap(t_game *g);
void		paint_grid(t_game *g, int x, int y, int color);

// mousemode.c
void		mouse_event(t_game *g);
void		mousemode_toggle(t_game *g);

// move.c
void		rotation_event(t_game *g);
void		move_event(t_game *g);

#endif
