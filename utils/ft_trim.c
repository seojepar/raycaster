/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_trim.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 18:34:17 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 20:39:44 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "utils.h"

char	*ft_trim(char *str)
{
	char	*s;
	char	*e;
	char	*it;
	int		was_space;

	it = str;
	was_space = 1;
	s = NULL;
	if (!str || !*str)
		return (NULL);
	while (*it)
	{
		if (!s && was_space && *it != ' ')
			s = it;
		if (!was_space && *it == ' ')
			e = it - 1;
		was_space = *it == ' ';
		it++;
	}
	if (!was_space)
		e = it - 1;
	return (ft_substr(s, e, 0));
}
