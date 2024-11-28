/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 21:16:40 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 21:25:27 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_to_buffer(char **buffer, char const *str)
{
	char	*ret;

	ret = ft_strjoin(*buffer, str);
	if (*buffer)
		free(*buffer);
	*buffer = ret;
	return (ret);
}
