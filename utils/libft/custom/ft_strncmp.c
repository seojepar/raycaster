/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:54:28 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/19 13:06:49 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 원래 버젼: 차이
// 수정버젼: TRUE, FALSE
int	ft_strnsame(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (1);
	return (0);
}
