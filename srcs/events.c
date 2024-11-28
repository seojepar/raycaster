/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   events.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/26 15:58:41 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 13:54:05 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	keycode_mapper(int key)
{
	if (key == KEY_A)
		return (0);
	else if (key == KEY_D)
		return (1);
	else if (key == KEY_W)
		return (2);
	else if (key == KEY_S)
		return (3);
	else if (key == KEY_LEFT)
		return (4);
	else if (key == KEY_RIGHT)
		return (5);
	else
		return (-1);
}

void	get_walk(int mask, t_vec *walk)
{
	int	left;
	int	right;
	int	up;
	int	down;

	left = ((mask & (1 << 0)) != 0);
	right = ((mask & (1 << 1)) != 0);
	up = ((mask & (1 << 2)) != 0);
	down = ((mask & (1 << 3)) != 0);
	walk->x = (-1 * left + right) * WALK;
	walk->y = (-1 * down + up) * WALK;
}

int	key_dn(int key, t_info *cub)
{	
	t_vec	walk;
	t_vec	next;
	int		idx;

	if (key == KEY_ESC)
		ft_close(cub);
	idx = keycode_mapper(key);
	if (idx < 0)
		return (0);
	cub->keyonoff |= (1 << idx);
	get_walk(cub->keyonoff, &walk);
	walk = mult_vv(cub->dir, walk);
	next = add_v(cub->pos, walk);
	if (cub->map[(int)next.y][(int)next.x] == WALL)
		return (0);
	printf("%f %f\n", next.x, next.y);
	if (key == KEY_RIGHT)
		cub->dir = rot_v(0.04, cub->dir);
	else if (key == KEY_LEFT)
		cub->dir = rot_v(-0.04, cub->dir);
	cub->pos = next;
	render(cub);
	return (1);
}

int	key_up(int key, t_info *cub)
{
	int	idx;

	idx = keycode_mapper(key);
	if (idx < 0)
		return (0);
	cub->keyonoff &= ~(1 << idx);
	(void)cub;
	return (0);
}

int	ft_close(t_info *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img);
	free_cub(cub);
	exit(1);
}
