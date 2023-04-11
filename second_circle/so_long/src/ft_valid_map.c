/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:16:34 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 15:35:35 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_search(struct s_map *m, char**v, int *item, struct s_cordi ch)
{
	char	*dx;
	char	*dy;
	int		nx;
	int		ny;

	if (*item == m->nr_c + 1)
		return ;
	dx = "001/\0";
	dy = "/100\0";
	v[ch.y][ch.x] = 1;
	while (*dx)
	{
		nx = ch.x + (int)(*dx - '0');
		ny = ch.y + (int)(*dy - '0');
		if (0 <= nx && nx < m->x && 0 <= ny && ny < m->y
			&& !v[ny][nx] && m->lines[ny][nx] != '1')
		{
			if (m->lines[ny][nx] == 'C' || m->lines[ny][nx] == 'E')
				*item += 1;
			v[ny][nx] = 1;
			ft_search(m, v, item, (struct s_cordi){nx, ny});
		}
		dx += 1;
		dy += 1;
	}
}

static int	ft_valid_path(struct s_map *m)
{
	int		answer;
	char	**visited;
	int		idx;

	idx = 0;
	visited = (char **)malloc(sizeof(char *) * m->y);
	if (!visited)
		return (1);
	while (idx < m->y)
	{
		visited[idx] = malloc(sizeof(char) * m->x);
		if (!visited[idx])
		{
			ft_free((void **)visited, idx);
			return (1);
		}
		ft_bzero(visited[idx], sizeof(char) * m->x);
		idx += 1;
	}
	answer = 0;
	ft_search(m, visited, &answer, m->ch);
	ft_free((void **)visited, m->y);
	free(visited);
	return (answer != (m->nr_c + 1));
}

static int	ft_check_wall(struct s_map *m)
{
	int	idx;

	idx = 0;
	while (idx < m->x)
	{
		if (m->lines[0][idx] != '1' || m->lines[m->y - 1][idx] != '1')
			return (1);
		idx += 1;
	}
	idx = 0;
	while (idx < m->y)
	{
		if (m->lines[idx][0] != '1' || m->lines[idx][m->x - 1] != '1')
			return (1);
		idx += 1;
	}
	return (0);
}

int	ft_valid_map(struct s_map *m)
{
	if (m->nr_e != 1 || m->nr_p != 1 || m->nr_c < 1)
		return (1);
	if (ft_check_wall(m))
		return (1);
	if (ft_valid_path(m))
		return (1);
	return (0);
}
