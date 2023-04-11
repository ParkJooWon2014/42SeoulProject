/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:19:31 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 12:40:07 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_node_idx(struct s_node *node, int prio)
{
	struct s_node	*tmp;
	int				ret;

	ret = 0;
	tmp = node->nxt;
	if (node->priority == prio)
		return (ret);
	while (tmp != node)
	{
		ret += 1;
		if (tmp->priority == prio)
			return (ret);
		tmp = tmp->nxt;
	}
	return (-1);
}

int	ft_find_node_move_top(struct s_stack *s, int type, int prio)
{
	struct s_stack	*stack;
	int				idx;
	int				size;

	stack = s + type;
	idx = ft_find_node_idx(stack ->top, prio);
	if (idx == -1)
		return (1);
	else if (idx == 0)
		return (0);
	if (idx > (int)(stack ->size / 2))
	{
		size = stack ->size - idx;
		while (size --)
			operator(s, RA + type);
	}
	else
		while (idx --)
			operator(s, RRA + type);
	return (0);
}
