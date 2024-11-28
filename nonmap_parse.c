/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmap_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:30:19 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/27 12:41:54 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_nonmap(t_info *cub, t_line *line)
{
	while (gnl(line, 0) != NULL)
	{
		jump_blank(line, 0);
		if (*line->it == '\0')
			continue ;
		if (get_id(line) != SUCCESS)
		{
			if (is_map_line(line))
				return (0);
			else
				return (xerr("invalid id on file"));
		}
		else
		{
			jump_blank(line, 0);
			if (*line->it == '\0')
				return (xerr("blank filename on file"));
			else
				save_id_data(cub, line);
		}
	}
	return (xerr("no map on file"));
}
