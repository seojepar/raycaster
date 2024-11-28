/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_substr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 14:59:52 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 19:09:44 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

// 커스텀 버젼이다.. 앞에 free 할 수 있는 플래그가 있다.

char	*ft_substr(char *start, char *end, int free_flag)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(end - start + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		tmp[i] = *(start + i);
		i++;
	}
	tmp[i] = '\0';
	if (free_flag)
		free(start);
	return (tmp);
}
