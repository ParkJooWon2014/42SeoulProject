/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:49:47 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 18:08:12 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <limits.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	ret;
	unsigned int	len;

	ret = ft_strlen(src);
	if (size)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (ret);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (ret);
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}

static char	*ft_read_file(int fd, char **back_up, char *buffer)
{
	char		*old;
	ssize_t		bytes;

	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		*(buffer + bytes) = '\0';
		if (!*back_up)
			*back_up = ft_strdup("");
		old = *back_up;
		*back_up = ft_strjoin(old, buffer);
		if (!*back_up)
			return (NULL);
		free(old);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*back_up);
}

static char	*ft_get_next_line(char **line)
{
	char	*back;
	char	*ret;

	back = *line;
	while (*back != '\0' && *back != '\n')
		back ++;
	if (!*back)
		return (NULL);
	ret = ft_substr(*line, back - *line + 1, ft_strlen(back + 1));
	*(back + 1) = 0;
	if (!ret)
		return (NULL);
	if (!*ret)
	{
		free(line);
		return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lines[OPEN_MAX];
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (buffer);
	line = ft_read_file(fd, lines + fd, buffer);
	free(buffer);
	if (!line)
	{
		free(*(lines + fd));
		*(lines + fd) = NULL;
		return (line);
	}
	lines[fd] = ft_get_next_line(&line);
	return (line);
}
