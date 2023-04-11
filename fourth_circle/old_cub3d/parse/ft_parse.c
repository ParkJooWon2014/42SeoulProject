/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:59:00 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/20 13:11:14 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_parse.h>

static int	get_fd(char *file_name)
{
	int	fd;

	if(!file_name)
		return (-1);
	if (ft_strncmp(ft_strstr(file_name,".cub"), ".cub", 5))
		return (-1);
	fd = open(file_name, O_RDONLY, 0644);
	return (fd);
}

static int	get_info(int fd, char **line)
{
}

static int	get_line(int fd, char **_line)
{
	char	*line;

	*_line = get_next_line(fd);
	if (!(*line))
		return (0);
	line = *_line;
	while (ft_isspace(*line))
		line += 1;
	if (*line != '1' || *(line + ft_strlen(line) - 1) != '1')
		return (1);
	return (0);
}

