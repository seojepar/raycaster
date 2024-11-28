/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:57:43 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/18 16:55:17 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	// 널 들어오는 경우 다 차버림 (혹시 몰라서)
	if (len == 0 || src == dst || !src || !dst)
		return (dst);
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (1)
		{
			*((char *)dst + i) = *((char *)src + i);
			if (i == 0)
				break ;
			i--;
		}
	}
	return (dst);
}