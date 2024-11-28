/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:03:12 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/23 15:10:01 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
