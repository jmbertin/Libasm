#ifndef LIBASM_H
#define LIBASM_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(char const *str);
char	*ft_strcpy( char * destination, const char * source );
int		ft_strcmp( const char * first, const char * second );
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

#endif
