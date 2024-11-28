/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_endswith.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/13 17:56:45 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 18:27:58 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "utils.h"

int	ft_endswith(char *a, char *b)
{
	int	dl;

	if (!a || !b)
		return (0);
	dl = ft_strlen(a) - ft_strlen(b);
	if (dl < 0)
		return (0);
	a += dl;
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == '\0');
}
