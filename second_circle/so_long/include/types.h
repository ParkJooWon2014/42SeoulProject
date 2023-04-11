/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:56:36 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:01:59 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libfta/libft.h"
# include <mlx.h>

# define INIT_X -1
# define INIT_Y -1

# define NR_IMG 5

enum e_type
{
	CH,
	EXIT,
	WALL,
	COLL,
	GROUND,
};
struct s_cordi
{
	int	x;
	int	y;
};

struct s_image
{
	int		x;
	int		y;
	void	*src;
};

struct s_map
{
	int				x;
	int				y;
	int				nr_p;
	int				nr_c;
	int				nr_e;
	char			*line;
	char			**lines;
	struct s_cordi	ch;
};

struct s_game
{
	void			*mlx;
	void			*window;
	struct s_image	images[NR_IMG];
	struct s_map	map;
	int				nr_move;
	int				nr_frame;
};

#endif
