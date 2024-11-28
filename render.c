/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:25:54 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 13:00:24 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>
// ray->step = (t_vec){2 * (ray->dir.x > 0) - 1, 2 * (ray->dir.y > 0) - 1};
// next_mapy = (t_vec){ray->mapy + (1 + ray->step.x / 2), 
// 가독성 선택	

static void	loop_init(t_info * cub, t_ray * const ray)
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
	// printf("dx: %f, dy: %f\n",ray->deltadistx, ray->deltadisty);
	ray->hit = 0;
	ray->stepx = 1;
	ray->stepy = 1;
	if (ray->raydir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->pos.x - ray->mapx) * ray->deltadistx;
	}
	else
        ray->sidedistx = (ray->mapx + 1.0 - ray->pos.x) * ray->deltadistx;
    if (ray->raydir.y < 0)
	{
        ray->stepy = -1;
        ray->sidedisty = (ray->pos.y - ray->mapy) * ray->deltadisty;
	}
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
			r->side = 2 * (r->stepy > 0);
		}
		if (map[r->mapy][r->mapx] == WALL)
			r->hit = 1;
	}
	if (X_SIDE(r->side))
		r->perpwalldist = (double)((double)r->sidedistx - (double)r->deltadistx);
	else
		r->perpwalldist = (double)((double)r->sidedisty - (double)r->deltadisty);
}

// 변형이 없어도 구조체는 포인터로 넘기는게 이득
// line->start_pixel : line상에서의 위치 : text상에서 위치
// line의 화면 스크린 상에서의 시작점: (정중앙 - lineh/2) = (H - lineh)/2
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
			c = *((unsigned int *)cub->fill[C]);
		else if (py <= line->end_pixel)
		{
			text->y = ((int)text->pos) % text->h;
			text->pos += ratio;
			c = get_color_from_text(text);
			if (X_SIDE(side))
				c = (c >> 1) & 8355711;
		}
		else
			c = *((unsigned int *)cub->fill[F]);
		put_color_to_pixel(cub, px, py, c);
	}
}

int	ft_floor(double d)
{
	int	ret;

	ret = (int)d;
	return (ret);
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
	if (X_SIDE(ray->side))
		line->wallx = (double)ray->pos.y + ray->perpwalldist * ray->raydir.y;
	else
		line->wallx = (double)ray->pos.x + ray->perpwalldist * ray->raydir.x;
	text = cub->fill[ray->side];
	line->wallx -= ft_floor(line->wallx);
	text->x = (int)(line->wallx * (double)text->w);
	if (ray->side == WE || ray->side == NO)
		text->x = text->w - 1 - text->x;
	draw_line(text, line, cub, ray->side);
}
void	pre_loop_init(t_info *cub, t_ray *ray)
{
	ray->dir = cub->dir;
	// plane: dir을 반시계 90도 회전
	ray->cplane = mult_v(0.66, rot_v(M_PI_2, ray->dir));
	ray->mapx = (int)ray->pos.x;
	ray->mapy = (int)ray->pos.y;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->x = 0;
}

// void	print_map(t_info *cub)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < cub->h)
// 	{
// 		x = 0;
// 		while (x < cub->w)
// 		{
// 			printf("%3d",cub->map[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }

int render(t_info *cub)
{
	t_ray		ray;
	t_draw		line;

	pre_loop_init(cub, &ray);
	// print_map(cub);
	while(ray.x < SCREEN_W)
	{
		loop_init(cub, &ray);
		hit_ray(cub->map, &ray);
		measure_line(cub, &ray, &line);
		ray.x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}