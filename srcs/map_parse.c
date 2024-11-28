/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_parse.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 19:55:20 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/27 15:23:19 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

const int	g_dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int	g_dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int	bfs(t_info *cub, int cx, int cy)
{
	int	cmap;
	int	i;

	cmap = cub->map[cy][cx];
	if (cmap == WALL || cmap < 0)
		return (0);
	else if (cmap == 0)
		return (ERROR);
	else if (cx == 0 || cx == cub->w - 1 || cy == 0 || \
		cy == cub->h - 1)
		return (ERROR);
	else
		cub->map[cy][cx] *= -1;
	i = 0;
	while (i < 8)
	{
		if (bfs(cub, cx + g_dx[i], cy + g_dy[i]))
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_map(t_info cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub.h)
	{
		x = 0;
		while (x < cub.w)
		{
			if (cub.map[y][x] == EMPTY && bfs(&cub, x, y))
				return (xerr("map is not surrounded by wall"));
			x++;
		}
		y++;
	}
	printf("Map is valid!\n");
	return (0);
}

void	save_map_size(t_info *cub, t_line *line)
{
	cub->h = line->h;
	cub->w = line->e - line->s + 1;
}

int	parse_map(t_info *cub, t_line *line)
{
	int	cnt;

	init_start_map(line);
	check_map_line(line);
	cnt = 1;
	while (++cnt && gnl(line, 1) && *line->in)
	{
		jump_blank(line, 1);
		if (!*line->it)
			continue ;
		else
			line->h = cnt;
		if (check_map_line(line))
			return (xerr("forbidden char in map"));
		if (line->pnum > 1)
			return (xerr("too many player in map"));
	}
	if (!is_empty_after_map(line))
		return (xerr("empty line in middle of map"));
	if (line->pnum != 1)
		return (xerr("no player in map"));
	save_map_size(cub, line);
	return (0);
}
