/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:37:31 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 13:51:26 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(struct s_stack *s)
{
	struct s_node	*a;

	a = s[STA].bottom->nxt;
	if (ft_is_sort(s + STA))
		return ;
	if (a->nxt->priority > a->priority && a->prv->priority > a->priority
		&& a->nxt->priority < a->prv->priority)
		operator(s, SA);
	else if (a->nxt->priority > a->priority && a->priority > a->prv->priority)
	{
		operator(s, SA);
		operator(s, RRA);
	}
	else if (a->nxt->priority > a->priority && a->priority < a->prv->priority)
		operator(s, RA);
	else if (a->nxt->priority < a->priority && a->priority > a->prv->priority
		&& a->prv->priority > a->nxt->priority)
	{
		operator(s, SA);
		operator(s, RA);
	}
	else
		operator(s, RRA);
}

void	sort_in_five(struct s_stack *s)
{
	struct s_stack	*a;

	a = s + STA;
	if (a->size == 2)
		operator(s, SA);
	else if (a->size == 3)
		sort_three(s);
	else if (a->size == 4)
	{
		ft_find_node_move_top(s, STA, 0);
		operator(s, PB);
		sort_three(s + STA);
		operator(s, PA);
	}
	else
	{
		ft_find_node_move_top(s, STA, 0);
		operator(s, PB);
		ft_find_node_move_top(s, STA, 1);
		operator(s, PB);
		sort_three(s + STA);
		operator(s, PA);
		operator(s, PA);
	}
}
