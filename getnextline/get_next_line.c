#include "get_next_line.h"
static int	ft_checknewline(char *s)
{
	int i;
	i = 0;
	while(s[i])
	{
		if(s[i++] == '\n')
		return(1);	
	}
	 return (0);
}
static int	ft_strnewline(char *s)
{
	int i;
	i = 0;
	while(s[i] != '\n')
	i++;
		return(i);	
}
static size_t	ft_strlen(const char *s)
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
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	s = src;
	d = dest;
	i = 0;
	if (!s && !d)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
static char	*ft_strcpy(char *src, char *dest)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * slen + 1);
	if (!dup)
		return (NULL);
	ft_strcpy((char *)s, dup);
	return (dup);
}
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	if (element_size != 0 && SIZE_MAX / element_size < num_elements)
		return (NULL);
	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
static	size_t	mlenf(size_t slen, unsigned int start, size_t len)
{
	if (slen - start < len)
		return (slen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	size;

	slen = ft_strlen(s);
	size = mlenf(slen, start, len);
	if (start >= slen)
	{
		return (ft_strdup(""));
	}
	if (!s)
		return (NULL);
	sub = (char *)ft_calloc((size + 1), sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy((char *)sub, (s + start), size);
	return (sub);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	tlen;
	char	*s;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
		
	if (!s1 && !s2)
		return (NULL);
	tlen = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (tlen + 1));
	if (!s)
		return (NULL);
	while (s1 && s1[++i])
	s[i] = s1[i];
	while (s2 && s2[++j])
	s[i + j] = s2[j];
	s[i + j] = '\0';
	free(s1);
	return (s);
}
char *get_next_line(int fd)
{
    char	*s_to_read;
	char *line;
    ssize_t	i;
	static char *b_read;
	static int check;

	s_to_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if(!s_to_read)
		return (NULL);
	while(ft_checknewline(s_to_read) == 0)
	{
		i = read(fd,s_to_read,BUFFER_SIZE);
		if (i <= 0)
			break;
		s_to_read[BUFFER_SIZE] = 0;
		if(check == 0)
		{
			b_read= ft_strdup(s_to_read);
			check =1;
		}
		else
		b_read = ft_strjoin(b_read, s_to_read);
	}
	if (ft_checknewline(b_read))
	{
		line = ft_substr(b_read,0,ft_strnewline(b_read) + 1);
		b_read = ft_substr(b_read,ft_strnewline(b_read) + 1,ft_strlen(b_read));
	}
	else
	{
		line = ft_substr(b_read,0,ft_strlen(b_read));
		return(NULL);
	}
	return(line);

}
int main()
{
		int fd = open("test.txt", O_RDONLY);
		char *s = get_next_line(fd);
		printf("%s",s);
		s = get_next_line(fd);
			printf("%s",s);
		s = get_next_line(fd);
			printf("%s",s);
		s = get_next_line(fd);
			printf("%s", s);
		s = get_next_line(fd);
			printf("%s", s);

		free(s);

}