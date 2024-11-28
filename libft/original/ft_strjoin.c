/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoin.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 16:50:46 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/19 21:38:02 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *a, char const *b)
{
	char	*join;
	size_t	alen;
	size_t	blen;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	join = malloc(alen + blen + 1);
	if (!join)
		return (NULL);
	ft_memmove(join, a, alen);
	ft_memmove(join + alen, b, blen);
	join[alen + blen] = '\0';
	return (join);
}
