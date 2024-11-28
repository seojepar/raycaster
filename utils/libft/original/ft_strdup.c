/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:10:18 by seojepar          #+#    #+#             */
/*   Updated: 2023/10/12 10:18:32 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(ft_strlen(s1) + 1);
	if (!tmp)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i <= ft_strlen(s1))
	{
		tmp[i] = s1[i];
		i++;
	}
	return (tmp);
}
