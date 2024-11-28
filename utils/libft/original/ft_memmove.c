/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memmove.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 14:57:43 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 16:55:17 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || src == dst || !src || !dst)
		return (dst);
	if (src > dst)
	{
		i = -1;
		while (++i < len)
			*((char *)dst + i) = *((char *)src + i);
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
