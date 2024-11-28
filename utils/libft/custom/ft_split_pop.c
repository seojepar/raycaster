// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split_pop.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/19 12:14:19 by seojepar          #+#    #+#             */
// /*   Updated: 2024/11/19 21:30:19 by seojepar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// char	*ft_split_pop(char const *str, char c)
// {
// 	char	*s;
//     char    *e;

//     s = ft_strchr(str, c);
//     e = ft_strchr(s, c);
//     if (!e)
//         return (NULL);
//     return (ft_substr(s, e - 1, 0));
// }
// // pop 하고, 위치 바꾸는 애도 하나 만들어야겠음.

// char	*ft_split_pop(char **str, char c)
// {
// 	char	*s;
//     char    *e;

//     s = ft_strchr(str, c);
//     e = ft_strchr(s, c);
//     if (!e)
//         return (NULL);
//     *str = 
//     return (ft_substr(s, e - 1, 0));
// }

// // 아니면.. 두번째 위치를 찾아주는 함수를 만들어야겠음.

// #include "libft.h"

// char	*ft_strnchr(char *s, char c, size_t n)
// {
// 	if (!s || !*s)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == c)
// 			n--;
// 		s++;
// 	}
// 	return (NULL);
// }