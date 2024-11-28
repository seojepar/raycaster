/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:12:09 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/27 13:21:11 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LINE_H
# define LINE_H

#include "libft.h"


# define SUCCESS 0
# define ERR_INVALID_ID 2
# define ERR_INVALID_MAP 3
# define ERR_BLANK_FILENAME 4
# define ERR_NOT_XPM 5
# define ERR_NO_MAP 6
# define STRERR_OPEN 7
# define ERR_MALLOC 8
# define ERR_XPM_CONVERT 10
# define ERR_RGB_RANGE 11
# define ERR_NO_COMMA 12
# define ERR_AFTER_RGB 13
# define MAP_START 20

// 이거 open strerr 써야되는건 어쩔?
// 언제쯤 이 친구들을 출력해줘야할지 모르겠다.

typedef struct s_line
{
	int		fd;
	char	*in; // original string
	/* for info */
	char	*it;
	int		id;
	/* for map */
	int		pnum; 
	int		s;
	int		e;
	int		h;
	char	*buf;
}				t_line;

enum	e_id {
	NO = 0,
	EA,
	SO,
	WE,
	F,
	C,
	ID_NUM,
};

#define IS_TEXTURE_ID(id) (NO <= (id) && (id) <= WE)	
#define IS_COLOR_ID(id) ((id == F) || (id == C))
#define ID_ARR {"NO", "EA", "SO", "WE", "F", "C"}
extern const char	*g_id[ID_NUM];
extern const char	*g_mapchar;

#define	MAP_DIR	"NESW"
#define MAP_OTR " 01"
#define MAP_ALL "NESW 01"


/* customed */
char	*gnl(t_line *line, int is_map);
void	jump_blank(t_line *line, int strict_flag);
int		get_id(t_line *line);
int		save_id_info(t_line *line);
int		is_map_line(t_line *line);
int		get_color(t_line *line, unsigned int *color);
int		is_empty_after_map(t_line *line);
void	init_start_map(t_line *line);
int		check_map_line(t_line *line);


/*
rgb value should be between 0 and 255"
*/
#endif