/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:48:54 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 16:08:57 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

int	get_id(t_line *line)
{
	int	i;

	i = 0;
	while (i < ID_NUM)
	{
		if (ft_startswith(line->it, g_id[i]))
		{
			line->id = i;
			line->it += ft_strlen(g_id[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_color(t_line *line, unsigned int *color)
{
	int		total;
	char	*it;

	total = 0;
	it = line->it;
	if (!*it)
		return (1);
	while (it && (*it == '+'))
		it++;
	while (*it && *it != ',')
	{
		if (*it != ' ')
			total = total * 10 + *it - '0';
		if (total >= 1000)
			return (1);
		it++;
	}
	if (!(0 <= total && total <= 255))
		return (1);
	*color = total;
	if (*it)
		line->it = it + 1;
	return (0);
}

int	check_map_line(t_line *line)
{
	int		last_nonblank_idx;
	char	*in;

	in = line->in;
	while (*in == ' ')
		in++;
	line->s = ft_min(line->s, in - line->in);
	while (*in)
	{
		if (*in != ' ')
			last_nonblank_idx = in - line->in;
		if (ft_strchr(MAP_DIR, *in))
			line->pnum++;
		else if (!ft_strchr(MAP_OTR, *in))
			return (xerr("forbidden char on map"));
		in++;
	}
	line->e = ft_max(line->e, last_nonblank_idx);
	return (0);
}

int	is_empty_after_map(t_line *line)
{
	while (gnl(line, 1))
	{
		jump_blank(line, 0);
		if (*line->in != '\0')
			return (0);
	}
	return (1);
}
