/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:18:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:02:30 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render_background(struct s_game *g)
{
	struct s_map	*map;
	char			**lines;
	int				x;
	int				y;

	x = 0;
	y = 0;
	map = &(g->map);
	lines = map->lines;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			if (ft_put_image(g, &g->images[GROUND], x, y))
				return (1);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

static int	ft_render_other(struct s_game *g, int x, int y)
{
	struct s_map	*map;
	char			**lines;
	struct s_image	*img;

	map = &(g->map);
	lines = map->lines;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			img = NULL;
			if (lines[y][x] == '1')
				img = g->images + WALL;
			else if (lines[y][x] == 'E')
				img = g->images + EXIT;
			else if (lines[y][x] == 'C')
				img = g->images + COLL;
			if (ft_put_image(g, img, x, y))
				return (1);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

static int	ft_render_ch(struct s_game *g)
{
	struct s_map	*map;

	map = &(g->map);
	return (ft_put_image(g, g->images + CH, map->ch.x, map->ch.y));
}

int	ft_render(struct s_game *g)
{
	struct s_map	*map;
	char			**lines;

	map = &(g->map);
	lines = map->lines;
	if (ft_render_background(g))
		return (1);
	if (ft_render_other(g, 0, 0))
		return (1);
	if (ft_render_ch(g))
		return (1);
	return (0);
}
