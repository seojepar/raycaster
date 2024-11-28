/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_put_color.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/26 13:50:30 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 11:59:34 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_color_from_text(t_text *text)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				d;
	size_t			idx;

	if (text->endian == 1)
		idx = text->size_line * text->y + (text->bpp / 8) * text->x + 1;
	else
		idx = text->size_line * text->y + (text->bpp / 8) * (text->x + 1) - 2;
	d = (text->endian) * 2 - 1;
	r = text->data[idx];
	g = text->data[idx + d];
	b = text->data[idx + 2 * d];
	return (b + (g << 8) + (r << 16));
}

void	put_color_to_pixel(t_info *cub, int x, int y, unsigned int color)
{
	size_t	idx;
	int		d;

	if (cub->endian == 1)
		idx = cub->size_line * y + (cub->bpp / 8) * x + 1;
	else
		idx = cub->size_line * y + (cub->bpp / 8) * (x + 1) - 2;
	d = (cub->endian) * 2 - 1;
	cub->data[idx] = ((color >> 16) & 255);
	cub->data[idx + d] = ((color >> 8) & 255);
	cub->data[idx + 2 * d] = ((color) & 255);
}

void	draw_line(t_text *text, t_draw *line, t_info *cub, int side)
{
	int				px;
	int				py;
	double			ratio;
	unsigned int	c;

	ratio = (double)text->h / line->h;
	text->pos = (line->start_pixel - (SCREEN_H - line->h) / 2) * ratio;
	px = line->x;
	py = -1;
	while (++py < SCREEN_H)
	{
		if (py < line->start_pixel)
		{
			c = *((unsigned int *)cub->fill[C]);
			put_color_to_pixel(cub, px, py, c);
		}
		else if (py <= line->end_pixel)
		{
			text->y = ((int)text->pos) % text->h;
			text->pos += ratio;
			c = get_color_from_text(text);
			if (side % 2 == 1)
				c = (c >> 1) & 8355711;
		}
		else
		{
			c = *((unsigned int *)cub->fill[F]);
			put_color_to_pixel(cub, px, py, c);
		}
	}
}
