/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:50:00 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 18:08:00 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	ch;

	tmp = (char *)s;
	ch = (char)c;
	while (*tmp)
	{
		if (*tmp == (ch))
			return (tmp);
		tmp ++;
	}
	if (*tmp == ch)
		return (tmp);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
		tmp += 1;
	return (tmp - str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (n && (!d && !s))
		return (d);
	if (!n)
		return (dst);
	while (n--)
		*d ++ = *s ++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	lens;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(*ret) * (lens + 1));
	if (!ret)
		return (ret);
	*ret = '\0';
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_memcpy(ret + ft_strlen(s1), s2, ft_strlen(s2));
	ret[lens] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	char	*ret;

	if (!s)
		return ((char *)s);
	lens = ft_strlen(s);
	if (!len)
		return (NULL);
	if (lens < len)
		len = lens;
	if (!lens || lens <= start)
	{	
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (ret);
		*ret = '\0';
		return (ret);
	}
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (ret);
	ft_strlcpy(ret, (char *)s + start, len + 1);
	return (ret);
}
