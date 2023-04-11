/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:27:08 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/20 13:43:28 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_move(int nr_move)
{
	ft_putstr_fd("number of movements : ", 1);
	ft_putnbr_fd(nr_move, 1);
	ft_putchar_fd('\n', 1);
}

static int	ft_valid_move(struct s_game *g, struct s_cordi nxt)
{
	struct s_map	*map;
	struct s_cordi	now;
	char			check;

	check = 0;
	map = &g->map;
	now = map->ch;
	if (0 <= nxt.x && nxt.x < map->x && 0 <= nxt.y && nxt.y < map->y
		&& map->lines[nxt.y][nxt.x] != '1')
	{
		if (map->lines[nxt.y][nxt.x] == 'C')
		{
			map->nr_c -= 1;
			map->lines[nxt.y][nxt.x] = '0';
		}
		map->ch = nxt;
		check = 1;
	}
	return (check);
}

static void	ft_is_exit(struct s_game *g)
{
	struct s_map	*map;
	struct s_cordi	ch;

	map = &(g->map);
	ch = map->ch;
	if (map->lines[ch.y][ch.x] == 'E' && !map->nr_c)
		ft_free_game(g, EXIT);
}

int	ft_keys(int key, struct s_game *g)
{
	struct s_cordi	nxt;
	char			check;

	check = 1;
	nxt = g->map.ch;
	if (key == KEY_ESC)
		ft_free_game(g, EXIT);
	else if (key == KEY_W)
		nxt.y -= 1;
	else if (key == KEY_A)
		nxt.x -= 1;
	else if (key == KEY_S)
		nxt.y += 1;
	else if (key == KEY_D)
		nxt.x += 1;
	else
		check = 0;
	if (check && ft_valid_move(g, nxt))
	{
		g->nr_move += 1;
		ft_render(g);
		ft_print_move(g->nr_move);
		ft_is_exit(g);
	}
	return (0);
}
