/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:44:12 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:10 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_valid_line(char *line)
{
	char	*map;

	map = line;
	if (!line)
		return (1);
	if (ft_strlen(line) < 3)
		return (1);
	while (*map && *map != '\n')
	{
		if (!(*map == 'E' || *map == 'P' || *map == '1'
				|| *map == '0' || *map == 'C'))
			return (1);
		map += 1;
	}
	return (0);
}

static int	ft_add_map_line(struct s_map *g, char *line)
{
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = g->line;
	if (ft_valid_line(line))
		return (1);
	g->line = ft_strjoin(g->line, line);
	if (!g->line)
		ret = 1;
	ft_count(g, line);
	free(tmp);
	g->y += 1;
	return (ret);
}

static int	ft_valid_file(char *file)
{
	return (ft_strlen(file) > 3
		&& ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) == 0);
}

static int	ft_valid_lines(struct s_map *g)
{
	int		idx;

	idx = 0;
	if (!g->lines)
		return (1);
	g->x = ft_strlen(g->lines[idx]);
	while (idx < g->y)
	{
		if (g->x < 2 || g->x != (int)ft_strlen(g->lines[idx]))
			return (1);
		idx += 1;
	}
	return (ft_valid_map(g));
}

int	ft_parse_input(struct s_map *g, char *file)
{
	int		fd;
	char	*line;

	if (!ft_valid_file(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (ft_add_map_line(g, line))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	ft_free_fd_line(fd, line);
	g->lines = ft_parse(g->line, g->y);
	return (ft_valid_lines(g));
}
