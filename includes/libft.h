#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *start, char *end, int free_flag);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
char    *ft_strjoin(char const *a, char const *b);
int	    ft_atoi(const char *nptr);
int	    ft_min(int a, int b);
int     ft_max(int a, int b);
void	*ft_calloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);
int	ft_isdigit(int c);


// char	*ft_split_pop(char const *s, char c);
int	    ft_strnsame(const char *s1, const char *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);


int     ft_isspace(const char *s);
int     ft_isblank(const char *s);
int     ft_startswith(const char *haystack, const char *needle);

# endif