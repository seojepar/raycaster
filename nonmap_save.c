/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonmap_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:52:25 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 12:07:17 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_valid_color_str(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ',')
			cnt++;
		if (!(ft_isdigit(*str) || *str == ' '))
			return (1); // invalid char
		str++;
	}
	if (cnt != 2)
		return (1); // comma 개수
	else
		return (0);
}

// 오직 0에서 9와 콤마만 허용하는 것으로!
static int	save_color(t_info *cub, t_line *line)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	// 셍긱 안한 케이스: +, 숫자와 ,가 아닌 문자가 들어오면?
	if (!is_valid_color_str(line->it))
		return (1);
	if (get_color(line, &r))
		return (ERR_RGB_RANGE);
	if (get_color(line, &g))
		return (ERR_RGB_RANGE);
	if (get_color(line, &b))
		return (ERR_RGB_RANGE);
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
		return (ERR_XPM_CONVERT);
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
	if (IS_TEXTURE_ID(id))
	{
		if (check_xpm_filename(line->it))
			return (1);
		ret = save_texture(cub, line);
	}
	else
		ret = save_color(cub, line);
	return (ret);
}
