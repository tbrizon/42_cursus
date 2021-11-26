#ifndef LIBFASM_H
# define LIBFASM_H
# include <stdlib.h>

size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char 	*ft_strdup(const char *s1);

#endif