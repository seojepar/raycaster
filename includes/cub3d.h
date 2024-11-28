/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:41:09 by seojeongpar       #+#    #+#             */
/*   Updated: 2024/11/28 12:10:22 by seojepar         ###   ########.fr       */
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
# include "mlx.h"
# include "line.h"
# include "utils.h"
# include "get_next_line.h"
# include "vector.h"

/* key val */
#define KEY_LEFT 	123
#define KEY_RIGHT	124
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_ESC		53
#define ON_DESTROY	17
#define WALK 0.1
#define ON_KEYDOWN	2
#define ON_KEYUP	3

# define FT_INT_MAX 2147483647
# define ERROR 1

/* parse_map.c */


/* check_map */
#define WALL ('1' - ' ')
#define EMPTY ('0' - ' ')

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
	int		x; // 텍스쳐 데이터 상의 x, y (화면이 아님)
	int		y;
	double	pos;
}				t_text;



/* parse_info.c */
#define VALID_CHAR_AFTER_ID(x) ((x != '\0') && (x != ' '))

#define MASK_R(x) ((x >> 16) & 255)
#define MASK_G(x) ((x >> 8) & 255)
#define MASK_B(x) ((x) &  255)

/* save map.c */
enum	e_side {
	N = 0,
	E,
	S,
	W,
};
#define X_SIDE(x) ((x) % 2 == 1)
extern const t_vec	g_nesw[5];
extern const int	g_dx[8];
extern const int	g_dy[8];


extern const int	g_move[4];

typedef struct s_ray{
	t_vec	pos; //x and y start position
	t_vec	dir; //initial direction vector
	t_vec	cplane; //the 2d raycaster version of camera plan
	t_vec	raydir;
	int		x; // cx라고 이름 붙일까 했는데, current x on screen
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
	int		side; // 홀수면 x, 짝수면 y
	double	perpwalldist;
}	t_ray;

typedef struct	s_draw{
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
	t_vec	pos; //x and y start position
	t_vec	dir; //initial direction vector
	double	time;
	double	old_time;
	void	*fill[ID_NUM];
}				t_info;


/* parse */
void	parse(t_info *cub, char *in);
int parse_map(t_info *cub, t_line *line);
int	save_map(t_info *cub, t_line *line);
int	init_map(t_info *cub);
int check_map(t_info cub);
int render(t_info *cub);
unsigned int    get_color_from_text(t_text *text);
void	put_color_to_pixel(t_info *cub, int x, int y, unsigned int color);
void    events(t_info *cub);
int	free_cub(t_info *cub);
/* parse_nonmap.c */
int	parse_nonmap(t_info *cub, t_line *line);

/* save_id_data.c */
int	save_id_data(t_info *cub, t_line *line);

int	xerr(char *str);
int	xxerr(const char *msg, const char *filename);
int	ft_close(t_info *cub);



#endif



