/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/04 19:53:25 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/27 15:38:49 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

// 피로감이 너무 극심해서 예전에 한걸 그대로 끌어왔다.

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	buho;

	i = 0;
	num = 0;
	buho = 1;
	while (nptr[i] != '\0')
	{
		if (!((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == ' ')))
			break ;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			buho = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i] != '\0')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * buho);
}
