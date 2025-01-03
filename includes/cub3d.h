/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:41:09 by seojeongpar       #+#    #+#             */
/*   Updated: 2024/11/28 16:29:32 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <math.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <mlx.h>
# include "line.h"
# include "utils.h"
# include "get_next_line.h"
# include "vector.h"

/* key val */
# define KEY_LEFT 	123
# define KEY_RIGHT	124
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC		53
# define ON_DESTROY	17
# define WALK 0.26
# define ON_KEYDOWN	2
# define ON_KEYUP	3

# define FT_INT_MAX 2147483647
# define ERROR 1

# define WALL ('1' - ' ')
# define EMPTY ('0' - ' ')

# define SCREEN_W 1000
# define SCREEN_H 800
# define ZOOM 1.0f

# define BOX_HEIGHT 1

typedef struct s_text{
	void	*img;
	char	*data;
	int		endian;
	int		bpp;
	int		size_line;
	int		h;
	int		w;
	int		x;
	int		y;
	double	pos;
}				t_text;

/* save map.c */
enum	e_side {
	N = 0,
	E,
	S,
	W,
};

extern const t_vec	g_nesw[5];
extern const int	g_dx[8];
extern const int	g_dy[8];
extern const int	g_move[4];

typedef struct s_ray{
	t_vec	pos;
	t_vec	dir;
	t_vec	cplane;
	t_vec	raydir;
	int		x;
	int		h;
	int		w;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
}	t_ray;

typedef struct s_draw{
	int		h;
	double	wallx;
	int		start_pixel;
	int		end_pixel;
	int		x;
}				t_draw;

typedef struct s_info{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		**map;
	int		h;
	int		w;
	t_vec	pos;
	t_vec	dir;
	double	time;
	int		keyonoff;
	void	*fill[ID_NUM];
	int		mask;
}				t_info;

/* parse */
void		parse(t_info *cub, char *in);
int			parse_map(t_info *cub, t_line *line);
int			save_map(t_info *cub, t_line *line);
int			init_map(t_info *cub);
int			heck_map(t_info cub);
int			render(t_info *cub);
void		put_color_to_pixel(t_info *cub, int x, int y, unsigned int color);
void		events(t_info *cub);
int			free_cub(t_info *cub);

/* parse_nonmap.c */
int			parse_nonmap(t_info *cub, t_line *line);

/* save_id_data.c */
int			save_id_data(t_info *cub, t_line *line);

int			xerr(char *str);
int			xxerr(const char *msg, const char *filename);
int			ft_close(t_info *cub);

/* render */
void		pre_loop_init(t_info *cub, t_ray *ray);
void		measure_line(t_info *cub, t_ray *ray, t_draw *line);
void		draw_line(t_text *text, t_draw *line, t_info *cub, int side);
void		hit_ray(int **map, t_ray *r);
void		loop_init(t_info *cub, t_ray *const ray);

/* events */
int			ft_close(t_info *cub);
int			key_up(int key, t_info *cub);
int			key_dn(int key, t_info *cub);
void		get_walk(int mask, t_vec *walk);
int			keycode_mapper(int key);

int			check_map(t_info cub);

#endif