/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:23:56 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/09 10:17:17 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "types.h"
# include "ft_node.h"
# include "ft_stack.h"
# include <stdio.h>

# define STA 0
# define STB 1

# define BUFFER_SIZE 1

enum e_type{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

char	*get_next_line(int fd);
void	coperator(struct s_stack *s, enum e_type type);
void	ft_quick_sort(int *tab, int start, int end);
void	ft_free(int nr, ...);
void	ft_parse_stack(int ac, char **av, struct s_stack *s, char *check);
int		ft_is_sort(struct s_stack *s);
void	operator(struct s_stack *s, enum e_type type);
void	sort_in_five(struct s_stack *s);
void	ft_indx_nodes(struct s_stack *s);
void	do_push_swap(struct s_stack *s);
int		ft_find_node_move_top(struct s_stack *s, int type, int prio);
void	ft_free_stack(struct s_stack *s);
#endif
