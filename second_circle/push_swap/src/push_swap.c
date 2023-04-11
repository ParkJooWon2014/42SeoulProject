/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:35:49 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 16:00:32 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cal_chunk(size_t size)
{
	size_t	idx;

	idx = 1;
	while (idx <= size / idx)
		idx += 1;
	return (idx * 3 / 2);
}

static void	a_to_b(struct s_stack *s, struct s_stack *a, int chunk)
{
	int				idx;

	idx = 0;
	while (!ft_stack_is_empty(a))
	{
		if (a->top->priority < idx)
		{
			operator(s, PB);
			idx += 1;
		}
		else if (idx <= a->top->priority && a->top->priority < (idx + chunk))
		{
			operator(s, PB);
			operator(s, RB);
			idx += 1;
		}
		else
		{
			operator(s, RA);
		}
	}
}

static void	b_to_a(struct s_stack *s)
{
	struct s_stack	*b;
	int				idx;

	b = s + STB;
	idx = (int)b->size - 1;
	while (!ft_stack_is_empty(b))
	{
		ft_find_node_move_top(s, STB, idx);
		operator(s, PA);
		idx -= 1;
	}
}

void	do_push_swap(struct s_stack *s)
{
	int		chunk;

	ft_indx_nodes(s + STA);
	if (s[STA].size <= 5)
		sort_in_five(s);
	else
	{
		chunk = ft_cal_chunk(s[STA].size);
		ft_indx_nodes(s + STA);
		a_to_b(s, s + STA, chunk);
		b_to_a(s);
	}
}
