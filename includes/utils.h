/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:40:39 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/30 11:17:58 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "libft.h"

int		ft_endswith(char *a, char *b);
int		ft_error(char *str);
int		ft_two_error(const char *msg, const char *filename);

#endif