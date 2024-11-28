/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/04 19:54:12 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/23 15:10:30 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		*(unsigned char *)(b + len) = (unsigned char)c;
	}
	return (b);
}
