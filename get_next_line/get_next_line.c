/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:58:00 by eayyildi          #+#    #+#             */
/*   Updated: 2022/01/09 16:58:00 by eayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		ls;
	char	*dup;

	i = 0;
	ls = ft_strlen(s);
	ls++;
	dup = malloc(ls);
	if (!dup)
		return (NULL);
	while (ls > 0)
	{
		dup[i] = s[i];
		i++;
		ls--;
	}
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != 0)
		dest[i] = s1[i];
	while (s2[j] != 0)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	free(s1);
	return (dest);
}*/
char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*read_word(int fd, char *buffer, char **s)
{
	int		size;
	char	*dest;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!*s)
			*s = ft_strdup(buffer);
		else
			*s = ft_strjoin(*s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	free(buffer);
	dest = ft_substr(*s, 0, ft_strchr(*s, '\n') - *s + 1);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (0);
	}
	dest = read_word(fd, buffer, &s);
	s = move_line(s);
	return (dest);
}
/*
int main()
{
    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);

    char *nl;
    char *yy;

        nl = get_next_line(fd1);
        yy = get_next_line(fd2);
        printf("%s", nl);
        printf("%s", yy);
    
    
    nl = get_next_line(fd1);
    yy = get_next_line(fd2);
    printf("%s", nl);
    printf("%s", yy);
    
}*/
