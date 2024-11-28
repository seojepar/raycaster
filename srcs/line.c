/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   line.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/26 20:22:50 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 11:39:55 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "line.h"

const char	*g_mapchar = "NESW 01";
const char	*g_id[ID_NUM] = {"NO", "EA", "SO", "WE", "F", "C"};

static int	is_loose_space(unsigned char c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int	is_strict_space(unsigned char c)
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
	line->buf = ft_strjoin(line->in, "\n");
	line->it = line->in;
	line->id = -1;
	line->pnum = 0;
	line->s = 2147483647;
	line->e = 0;
	line->h = 1;
}

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
