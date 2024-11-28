/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parse.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 19:50:35 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/27 15:22:44 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	exit_p(t_info *cub, t_line *line)
{
	free_cub(cub);
	free(line->in);
	free(line->buf);
	exit(1);
}

void	parse(t_info *cub, char *in)
{
	static t_line	line = {0};

	line.fd = open(in, O_RDONLY);
	parse_nonmap(cub, &line);
	if (cub->mask != ((1 << 6) - 1))
		xerr("missing id information on file");
	if (parse_map(cub, &line))
		exit_p(cub, &line);
	save_map(cub, &line);
	check_map(*cub);
	free(line.buf);
	return ;
}
