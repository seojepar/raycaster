/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_startswith.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/26 20:43:29 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/26 20:46:03 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(const char *haystack, const char *needle)
{
	while (*haystack && *needle && *haystack == *needle)
	{
		needle++;
		haystack++;
	}
	return (*needle == '\0');
}
