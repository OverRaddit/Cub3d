/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:18:19 by jinyoo            #+#    #+#             */
/*   Updated: 2022/07/21 15:33:26 by gshim            ###   ########.fr       */
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
# define _USE_MATH_DEFINES
# include <math.h>
# include <string.h> // memset

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

# define LAST 0
# define NO_COLOR -1
# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define MINIMAP_SCALE	0.25
# define M_UNIT			0.1		// 이동단위
# define R_UNIT			M_PI_4/4	// 회전단위
# define BODY_UNIT		0.1		// 벽과 플레이어와의 최소거리

# define RGB_Red 255*65536+0+0
# define RGB_Green 0*65536+255*256+0
# define RGB_Blue 0*65536+0*256+255
# define RGB_White 255*65536+255*256+255
# define RGB_Yellow 255*65536+255*256+0

typedef struct s_img
{
	void			*img;
	unsigned int	*data;

	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_player
{
	double	px;
	double	py;
	double	dirx;
	double	diry;
	char	starting_sight;
}	t_player;

typedef struct	s_texture
{
	char			*tex_path_malloc;
	unsigned int	*data;
	t_img			texture;
	int				width;
	int				height;
}	t_texture;

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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	wall;
	t_img	screen;
	t_img	minimap;
	t_map	*map;

	double	pX;
	double	pY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

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

	double	wallX;
	int		texX;
	int		texY;

	double	step;
	double	texPos;
	int		miniW;
	int		miniH;
	int		gridW;
	int		gridH;
}	t_game;

//error.c
int		exit_event(t_map *map);
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

// cub3d_init.c
void	player_init(t_game *g);
void	img_init(t_game *game);
int		window_init(t_game *game);

// deal_key.c
void	move(t_game *game, double angle);
void	rotate(t_game *game, double angle);
int		deal_key(int key_code, t_game *game);

// ray_cal.c
void	ray_cal_init(t_game *g, int x);
void	getsidedist(t_game *g);
void	dda(t_game *g);
void	getdrawpoint(t_game *g);
void	cal_texture(t_game *g, t_texture wall_tex);

// ray_render.c
void		drawline(t_game *g, t_texture wall_tex, unsigned int *data, unsigned int *screen, int x);
void		setscreen(t_game *g, unsigned int *screen);
t_texture	getwalltexture(t_game *g);

// minimap.c
void	paint_minimap(t_game *g, unsigned int *minimap);
void	paint_grid(t_game *g, unsigned int* minimap, int x, int y, int color);

#endif
