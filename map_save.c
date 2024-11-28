/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:06:58 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 13:46:34 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const t_vec	g_nesw[5] = {{0, -1}, {+1, 0}, {0, +1}, {-1, 0}};

int	init_map(t_info *cub)
{
	int	i;

	cub->map = malloc(sizeof(int *) * cub->h);
	if (!cub->map)
	{
		free_cub(cub);
		return (1);
	}	
	i = 0;
	while (cub->map && i < cub->h)
	{
		cub->map[i] = ft_calloc(sizeof(int) * cub->w);
		if (!cub->map[i])
		{
			free_cub(cub);
			return (1);
		}
		i++;
	}
	return (0);
}

void	save_map_unit(char c, t_info *cub, int x, int y)
{
	int		dir;
	char	*base;

	if (ft_strchr(MAP_OTR, c))
		cub->map[y][x] = (c - ' ');
	else
	{
		base = MAP_DIR;
		dir = ft_strchr(base, c) - base;
		cub->pos = (t_vec){(double)x, (double)y};
		cub->dir = g_nesw[dir];
		cub->map[y][x] = EMPTY;
	}
}

int	save_map(t_info *cub, t_line *line)
{
	char	*str;
	int		x;
	int		y;

	
	if (init_map(cub))
		return (1);
	str = line->buf + line->s;
	y = 0;
	while (y < cub->h)
	{
		x = 0;
		while (*str && *str != '\n')
		{
			save_map_unit(*str, cub, x, y);
			x++;
			str++;
		}
		y++;
		if (!*str)
			break;
		str = ft_strchr(str, '\n') + line->s + 1;
	}
	return (0);
}
