/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:50:30 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 11:59:34 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int    get_color_from_text(t_text *text)
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

	if (cub->endian == 1) // ARGB (순서대로)
		idx = cub->size_line * y + (cub->bpp / 8) * x + 1;
	else // (뒤에서부터 저장) BGRA
		idx = cub->size_line * y + (cub->bpp / 8) * (x + 1) - 2;
	d = (cub->endian) * 2 - 1;
	cub->data[idx] = MASK_R(color);
	cub->data[idx + d] = MASK_G(color);
	cub->data[idx + 2 * d] = MASK_B(color);
}
