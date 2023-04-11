/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:10:30 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:03:23 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(struct s_game *g)
{
	ft_bzero(g, sizeof(*g));
	g->map.x = INIT_X;
	g->map.line = ft_strdup("");
}

static int	ft_set_images(struct s_game *g)
{
	g->images[CH].src = mlx_xpm_file_to_image(g->mlx, PATH_CH,
			&(g->images[CH].x), &(g->images[CH].y));
	g->images[WALL].src = mlx_xpm_file_to_image(g->mlx, PATH_WALL,
			&(g->images[WALL].x), &(g->images[WALL].y));
	g->images[EXIT].src = mlx_xpm_file_to_image(g->mlx, PATH_EXIT,
			&(g->images[EXIT].x), &(g->images[EXIT].y));
	g->images[COLL].src = mlx_xpm_file_to_image(g->mlx, PATH_COLL,
			&(g->images[COLL].x), &(g->images[COLL].y));
	g->images[GROUND].src = mlx_xpm_file_to_image(g->mlx, PATH_GROUND,
			&(g->images[GROUND].x), &(g->images[GROUND].y));
	if (!g->images[CH].src || !g->images[WALL].src || !g->images[EXIT].src
		|| !g->images[COLL].src || !g->images[GROUND].src)
		return (1);
	return (0);
}

int	ft_game_set_init(struct s_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (1);
	g->window = mlx_new_window(g->mlx, g->map.x * TILE_SIZE,
			g->map.y * TILE_SIZE, "42-seoul-joowpark-so_long");
	if (!g->window)
	{
		free(g->mlx);
		return (1);
	}
	if (ft_set_images(g))
		ft_free_game(g, EXIT);
	return (0);
}
