/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strchr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 15:00:03 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/19 22:22:54 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s || !(*s))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
