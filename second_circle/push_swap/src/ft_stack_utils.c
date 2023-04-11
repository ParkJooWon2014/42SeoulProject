/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:40 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 12:43:53 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_append_tab(struct s_stack *s, int *tabs, int nr_item)
{
	int		idx;

	idx = 0;
	while (idx < nr_item)
	{
		ft_stack_append_init(s, ft_malloc_node(tabs[idx]));
		idx ++;
	}
}

void	swap(struct s_stack *s)
{
	struct s_node	*first;
	struct s_node	*second;

	if (s->size < 2)
		return ;
	first = ft_stack_pop(s);
	second = ft_stack_pop(s);
	ft_stack_append(s, first);
	ft_stack_append(s, second);
}

void	push(struct s_stack *a, struct s_stack *b)
{
	struct s_node	*node;

	if (ft_stack_is_empty(b))
		return ;
	node = ft_stack_pop(b);
	if (!node)
		return ;
	ft_stack_append(a, node);
}

void	rotate(struct s_stack *s)
{
	if (ft_stack_is_empty(s))
		return ;
	s->bottom = s->bottom->prv;
	s->top = s->top->prv;
}

void	rrotate(struct s_stack *s)
{
	if (ft_stack_is_empty(s))
		return ;
	s->bottom = s->bottom->nxt;
	s->top = s->top->nxt;
}
