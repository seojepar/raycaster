/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:54:12 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/23 15:10:30 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// libft 과거 그대로 복사함
// 다시 구현하려고 했는데, char로만 한게 문제였음. unsigned char 로 해야지 0이 0으로 들어갔음..!!
void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		*(unsigned char *)(b + len) = (unsigned char)c;
	}
	return (b);
}

