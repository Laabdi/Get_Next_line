#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
	return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}


char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
	return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	line = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!line)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i] != '\0')
			line[i] = stash[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (line);
}