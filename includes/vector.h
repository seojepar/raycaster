/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:14:27 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/28 13:29:59 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vec{
	double x;
	double y;
}				t_vec;

t_vec	add_v(t_vec v1, t_vec v2);
t_vec	mult_v(double scalar, t_vec vector);
t_vec	rot_v(double angle, t_vec vector);
double	abs_d(double d);
t_vec	mult_vv(t_vec a, t_vec b);

#endif