/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_check.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/23 14:30:40 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/27 15:38:38 by seojepar		 ###   ########.fr	   */
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
				return (ERROR);
			x++;
		}
		y++;
	}
	printf("Map is valid!\n");
	return (0);
}
