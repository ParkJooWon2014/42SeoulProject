/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:09:25 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:48:55 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>  // system, atexit 함수를 사용하기 위해 추가.
#include <string.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	struct s_game	g;

	if (ac < 2)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	av += 1;
	ft_game_init(&g);
	if (ft_parse_input(&(g.map), *av))
	{
		ft_free_game(&g, RETURN);
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	ft_game_set_init(&g);
	ft_print_move(g.nr_move);
	ft_render(&g);
	mlx_hook(g.window, X_EVENT_KEY_UP, 0, &ft_keys, &g);
	mlx_hook(g.window, ON_DESTROY, 0, &ft_free_game_exit, &g);
	mlx_loop(g.mlx);
	return (0);
}
