/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojepar <seojepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:30:58 by seojepar          #+#    #+#             */
/*   Updated: 2024/11/27 12:35:57 by seojepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
t_list				*get_node(int fd, t_list **tmp);
char				*set_buf(t_list **fdl, int fd, char *nextbuf);
void				ft_lstclear(t_list **lst);
void				free_node(int fd, t_list **fdl);
char				*get_total(int fd, t_list *fdl);

#endif