/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:45:32 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 15:10:05 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count(struct s_map *m, char *line)
{
	char	*cmd;

	cmd = line;
	while (*line)
	{
		if (*line == 'P')
		{
			m->ch = (struct s_cordi){line - cmd, m->y};
			m->nr_p += 1;
		}
		if (*line == 'C')
			m->nr_c += 1;
		if (*line == 'E')
			m->nr_e += 1;
		line += 1;
	}
}

int	ft_put_image(struct s_game *g, struct s_image *img, int x, int y)
{
	if (img && !mlx_put_image_to_window(g->mlx, g->window, img->src,
			x * TILE_SIZE, y * TILE_SIZE))
		return (1);
	return (0);
}
