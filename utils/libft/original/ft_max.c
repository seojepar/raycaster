/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_max.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 20:01:15 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/18 20:01:58 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
