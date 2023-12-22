#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *read_left(char *str);
char *read_right(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strchr(char *s, int c);

# endif