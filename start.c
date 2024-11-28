/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:29:47 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 14:39:12 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_info *cub)
{
	t_ray		ray;
	t_draw		line;

	pre_loop_init(cub, &ray);
	while (ray.x < SCREEN_W)
	{
		loop_init(cub, &ray);
		hit_ray(cub->map, &ray);
		measure_line(cub, &ray, &line);
		ray.x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	events(t_info *cub)
{
	mlx_hook(cub->win, ON_KEYDOWN, 0, key_dn, cub);
	mlx_hook(cub->win, ON_KEYUP, 0, key_up, cub);
	mlx_hook(cub->win, ON_DESTROY, 0, ft_close, cub);
	mlx_loop(cub->mlx);
}
