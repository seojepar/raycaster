/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   gnl_info.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/26 20:16:00 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/27 15:19:29 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "line.h"
#include "get_next_line.h"

static char	*update_buffer(t_line *line)
{
	char	*add_newline;
	char	*ret;

	add_newline = ft_strjoin(line->in, "\n");
	if (!line->buf)
		line->buf = ft_strdup(add_newline);
	else
	{
		ret = ft_strjoin(line->buf, add_newline);
		free(line->buf);
		free(add_newline);
		line->buf = ret;
	}
	return (line->buf);
}

char	*gnl(t_line *line, int is_map)
{
	if (line->in)
		free(line->in);
	line->in = get_next_line(line->fd);
	line->it = line->in;
	if (is_map)
		update_buffer(line);
	return (line->in);
}

char	*gnl_info(t_line *line)
{
	line->id = -1;
	if (line->in)
		free(line->in);
	line->in = get_next_line(line->fd);
	line->it = line->in;
	return (line->in);
}
