/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:55:20 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/27 15:23:19 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_size(t_info *cub, t_line *line)
{
	cub->h = line->h;
	cub->w = line->e - line->s + 1;
}

int parse_map(t_info *cub, t_line *line)
{
	int	cnt;

	init_start_map(line);
	check_map_line(line);
	cnt = 1;
	while (++cnt && gnl(line, 1) && *line->in)
	{
		jump_blank(line, 1);
		if (!*line->it)
			continue;
		else
			line->h = cnt;
		if (check_map_line(line))
			return (xerr("forbidden char in map"));
		if (line->pnum > 1)
			return (xerr("too many player in map"));
	}
	if (!is_empty_after_map(line))
		return (xerr("empty line in middle of map"));
	save_map_size(cub, line);
	return (0);
}

