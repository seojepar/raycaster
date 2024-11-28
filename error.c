/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:16:43 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/27 15:23:55 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	xerr(char *str)
{
	if (!str || !*str)
		return (1);
	else
	{
		write(STDERR_FILENO, "Error\n: ", 8);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "\n", 1);
	}
	// free cub?
	exit(1);
	return (1);
}

int	xxerr(const char *msg, const char *filename)
{
	write(STDERR_FILENO, "Error\n: ", 8);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, filename, ft_strlen(filename));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}