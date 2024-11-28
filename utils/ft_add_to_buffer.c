/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:16:40 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/18 21:25:27 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 얘도 커스텀 되었다. 원래 strlcat은 1차원 2개를 받아서 뒤에 이어붙이는 개념이다.
// 근데 이건 아니다.

// 이거 사실 ret 널이면 위에 base 말록 해제 안할까 하다가 그냥 해버림. 에러처리하기 쉽게
// 우연히.. ft_strlcat(char *dst, const char *src, size_t dstsize) libft 에서 발견함.
// 이거 이미 있는 함수였음.... 그래서 또 바꿈. ㅋㅋ

// 이거 아무래도 안쓸거 같음. ftstrlcat 에서 그냥 
// add_to_buffer 함수로 바꿈.

#include "libft.h"

char	*ft_add_to_buffer(char **buffer, char const *str)
{
	char *ret;

	ret = ft_strjoin(*buffer, str);
	if (*buffer)
		free(*buffer);
	*buffer = ret;
	return (ret);
}