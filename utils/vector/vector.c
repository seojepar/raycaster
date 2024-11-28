/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vector.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/23 12:21:14 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 13:55:07 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "vector.h"

t_vec	add_v(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	return (ret);
}

t_vec	mult_v(double scalar, t_vec vector)
{
	t_vec	ret;

	ret.x = vector.x * scalar;
	ret.y = vector.y * scalar;
	return (ret);
}

t_vec	rot_v(double rad, t_vec vector)
{
	t_vec	ret;

	ret.x = vector.x * cos(rad) - sin(rad) * vector.y;
	ret.y = vector.x * sin(rad) + cos(rad) * vector.y;
	return (ret);
}

double	abs_d(double d)
{
	if (d > 0)
		return (d);
	else
		return (-1.0f * d);
}

t_vec	mult_vv(t_vec y, t_vec key)
{
	t_vec	x;
	t_vec	ret;

	x = rot_v(M_PI_2, y);
	ret.x = x.x * key.x + y.x * key.y;
	ret.y = x.y * key.x + y.y * key.y;
	return (ret);
}
