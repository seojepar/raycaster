/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:22:50 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 11:39:55 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

const char	*g_mapchar = "NESW 01";
const char	*g_id[ID_NUM] = ID_ARR;


static int is_loose_space(unsigned char c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int is_strict_space(unsigned char c)
{
	return (c == ' ');
}

void	jump_blank(t_line *line, int strict_flag)
{
	char	*it;
	int		(*fptr)(unsigned char);

	it = line->it;
	if (strict_flag)
		fptr = is_strict_space;
	else
		fptr = is_loose_space;
	while (*it && (*fptr)(*it))
		it++;
	line->it = it;
}

void	init_start_map(t_line *line)
{
	line->buf = ft_strjoin(line->in, "\n"); // 가드 안함
	line->it = line->in;
	line->id = -1;
	line->pnum = 0;
	line->s = 2147483647;
	line->e = 0;
	line->h = 1;
}

#include <stdio.h>

int	is_map_line(t_line *line)
{
	char	*in;

	in = line->in;
	while (*in && ft_strchr(MAP_ALL, *in))
		in++;
	if (*in == '\0')
		return (1);
	return (0);
}

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

// 스페이스 다음에 1인가, 0과 스페이스가 맞닿지는 않는지 확인해야함.
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
			return (1); // non valid map char
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