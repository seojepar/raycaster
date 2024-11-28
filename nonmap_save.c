/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   nonmap_save.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 19:52:25 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 12:17:39 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_color_str(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ',')
			cnt++;
		else if (!(ft_isdigit(*str) || *str == ' '))
			return (xerr("forbidden char in rgb field"));
		str++;
	}
	if (cnt != 2)
		return (xerr("should be 2 commas in rgb field"));
	else
		return (0);
}

static int	save_color(t_info *cub, t_line *line)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (!is_valid_color_str(line->it))
		return (1);
	if (get_color(line, &r) || get_color(line, &g) || get_color(line, &b))
		return (xerr("color is not in range"));
	else
	{	
		*((unsigned int *)cub->fill[line->id]) = (r << 16) + (g << 8) + b;
		return (0);
	}
}

static int	check_xpm_filename(char *filename)
{
	if (!ft_endswith(filename, ".xpm"))
		return (xerr("texture file is not an xpm file"));
	else if (open(filename, O_RDONLY) == -1)
		return (xerr(strerror(errno)));
	return (0);
}

static int	save_texture(t_info *cub, t_line *line)
{
	t_text	*t;

	t = cub->fill[line->id];
	t->img = mlx_xpm_file_to_image(cub->mlx, line->it, &t->w, &t->h);
	if (!t->img)
		return (xerr("xpm to image convert failed"));
	else
	{
		t->data = mlx_get_data_addr(t->img, &t->bpp, &t->size_line, &t->endian);
		return (0);
	}
}

int	save_id_data(t_info *cub, t_line *line)
{
	int	id;
	int	ret;

	id = line->id;
	if (is_texture_id(id))
	{
		if (check_xpm_filename(line->it))
			return (1);
		ret = save_texture(cub, line);
	}
	else
		ret = save_color(cub, line);
	return (ret);
}
