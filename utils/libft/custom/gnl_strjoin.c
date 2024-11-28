/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:00:11 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/18 16:50:36 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

// 이거 아무래도 gnl 전용으로 만들었던거 같으니까 재탕은 금지다.
char	*gnl_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tmp = (char *)malloc(len);
	if (!tmp)
	{
		free(s1);
		return (NULL);
	}
	ft_memmove(tmp, s1, ft_strlen(s1));
	ft_memmove(tmp + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	i = 0;
	while (i <= BUFFER_SIZE)
		s2[i++] = '\0';
	free(s1);
	return (tmp);
}
