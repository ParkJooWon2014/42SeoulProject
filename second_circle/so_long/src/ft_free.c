/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:43:18 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:36:50 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void **ptr, int end)
{
	int	idx;

	idx = 0;
	while (idx < end)
	{
		free(ptr[idx]);
		idx ++;
	}
}

void	ft_free_fd_line(int fd, char *line)
{
	close(fd);
	free(line);
}

static void	ft_mlx_free(void *mlx)
{
	if (mlx)
		free(mlx);
}

int	ft_free_game(struct s_game *g, int type)
{
	int		idx;

	idx = 0;
	while (idx < NR_IMG)
	{
		if (g->images[idx].src)
		{
			mlx_destroy_image(g->mlx, g->images[idx].src);
		}
		idx += 1;
	}
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->map.lines)
		free(g->map.lines);
	if (g->map.line)
		free(g->map.line);
	ft_mlx_free(g->mlx);
	if (type == EXIT)
		exit(1);
	return (0);
}

int	ft_free_game_exit(struct s_game *g)
{
	return (ft_free_game(g, EXIT));
}
