/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 04:42:44 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/29 04:42:50 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <unistd.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ch)
	{
		return ((char *)&str[i]);
	}	
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j + i] = s2[i];
		i++;
	}
	s[i + j] = '\0';
	return (s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dst, const void *src)
{
	char		*dp;
	const char	*sp;

	dp = (char *)dst;
	sp = (const char *)src;
	if (!dp && !sp)
		return (dst);
	while (src)
	{
		*dp++ = *sp++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *buf;
    char        *newline_pos;
    char        *line;
    char        *temp;
    ssize_t     bytes_read;
    size_t      buffer_size = 5;

    buf = malloc(buffer_size + 1);
    if (!buf)
        return (NULL);

    while ((bytes_read = read(fd, buf, buffer_size)) > 0)
    {
        buf[bytes_read] = '\0';
        if (save)
            save = ft_strjoin(save, buf);
        else
            save = ft_strdup(buf);
        if ((newline_pos = ft_strchr(save, '\n')))
            break;
    }
    free(buf);
    if (bytes_read < 0 || (!save && bytes_read == 0))
        return (NULL);

    newline_pos = ft_strchr(save, '\n');
    if (newline_pos)
    {
        line = ft_substr(save, 0, newline_pos - save + 1);
        temp = ft_strdup(newline_pos + 1);
        free(save);
        save = temp;
    }
    else
    {
        line = ft_strdup(save);
        free(save);
        save = NULL;
    }
    return (line);
}

