/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   render.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/23 15:25:54 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 13:00:24 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	loop_init(t_info *cub, t_ray *const ray)
{
	double	cplanex;

	ray->pos = cub->pos;
	ray->mapx = (int)ray->pos.x;
	ray->mapy = (int)ray->pos.y;
	cplanex = (double) 2 * ray->x / SCREEN_W - 1;
	ray->raydir.x = ray->dir.x + ray->cplane.x * cplanex;
	ray->raydir.y = ray->dir.y + ray->cplane.y * cplanex;
	ray->deltadistx = abs_d(1.0f / ray->raydir.x);
	ray->deltadisty = abs_d(1.0f / ray->raydir.y);
	ray->hit = 0;
	ray->stepx = (ray->raydir.x >= 0) * 2 - 1;
	ray->stepy = (ray->raydir.y >= 0) * 2 - 1;
	if (ray->raydir.x < 0)
		ray->sidedistx = (ray->pos.x - ray->mapx) * ray->deltadistx;
	else
		ray->sidedistx = (ray->mapx + 1.0 - ray->pos.x) * ray->deltadistx;
	if (ray->raydir.y < 0)
		ray->sidedisty = (ray->pos.y - ray->mapy) * ray->deltadisty;
	else
		ray->sidedisty = (ray->mapy + 1.0 - ray->pos.y) * ray->deltadisty;
}

void	hit_ray(int **map, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 1 + 2 * (r->stepx > 0);
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 2 * (r->stepy < 0);
		}
		if (map[r->mapy][r->mapx] == WALL)
			r->hit = 1;
	}
	if (r->side % 2 == 1)
		r->perpwalldist = (double)(r->sidedistx - r->deltadistx);
	else
		r->perpwalldist = (double)(r->sidedisty - r->deltadisty);
}

void	measure_line(t_info *cub, t_ray *ray, t_draw *line)
{
	t_text	*text;

	line->x = ray->x;
	line->h = (int)(ZOOM * SCREEN_H / ray->perpwalldist);
	line->start_pixel = (SCREEN_H - line->h) / 2;
	if (line->start_pixel < 0)
		line->start_pixel = 0;
	line->end_pixel = (SCREEN_H + line->h) / 2;
	if (line->end_pixel >= SCREEN_H)
		line->end_pixel = SCREEN_H - 1;
	if (ray->side % 2 == 1)
		line->wallx = ray->pos.y + ray->perpwalldist * ray->raydir.y;
	else
		line->wallx = ray->pos.x + ray->perpwalldist * ray->raydir.x;
	text = cub->fill[ray->side];
	line->wallx -= (int)(line->wallx);
	text->x = (int)(line->wallx * (double)text->w);
	if (ray->side == WE || ray->side == NO)
		text->x = text->w - 1 - text->x;
	draw_line(text, line, cub, ray->side);
}

void	pre_loop_init(t_info *cub, t_ray *ray)
{
	ray->dir = cub->dir;
	ray->cplane = mult_v(0.66, rot_v(M_PI_2, ray->dir));
	ray->mapx = (int)ray->pos.x;
	ray->mapy = (int)ray->pos.y;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->x = 0;
}
