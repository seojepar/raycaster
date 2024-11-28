/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:41 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 12:08:42 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_dn(int key, t_info *cub)
{	
	t_vec	walk;
	int		nx;
	int		ny;

	if (key == KEY_ESC)
		ft_close(cub);
	walk.x = ((-1) * (key == KEY_A) + (key == KEY_D)) * WALK;
	walk.y = ((-1) * (key == KEY_W) + (key == KEY_S)) * WALK;
	nx = walk.x + cub->pos.x;
	ny = walk.y + cub->pos.y;
	if (cub->map[ny][nx] == WALL)
		return (0);
	if (key == KEY_RIGHT)
		cub->dir = rot_v(0.1, cub->dir);
	else if (key == KEY_LEFT)
		cub->dir = rot_v(-0.1, cub->dir);
	cub->pos = add_v(cub->pos, walk);
	render(cub);
	return (1);
}

int	key_up(int key, t_info *cub)
{
	printf("%d\n", key);
	(void)cub;
	return (1);
}

int	ft_close(t_info *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img);
	free_cub(cub);
	exit(1);
}

int	main_loop(t_info *cub)
{
	(void)cub;
	return(1);
}

void    events(t_info *cub)
{
	printf("clean\n");
	// mlx_hook(cub->win, ON_KEYDOWN, 0, key_dn, cub);
	// mlx_hook(cub->win, ON_KEYUP, 0, key_up, cub);
	// mlx_loop_hook(cub->win, main_loop, cub);
	// // mlx_hook(cub->win, ON_DESTROY, 0, ft_close, cub);
	// mlx_hook(cub->win, ON_DESTROY, 0, ft_close, cub);
	mlx_loop(cub->mlx);
}