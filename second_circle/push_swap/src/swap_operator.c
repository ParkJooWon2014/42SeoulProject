/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:10:12 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 14:36:27 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__other_operator(struct s_stack *s, enum e_type type)
{
	if (type == SS)
	{
		swap(&s[STA]);
		swap(&s[STB]);
		ft_putstr_fd("ss\n", 1);
	}
	else if (type == RR)
	{
		rotate(&s[STA]);
		rotate(&s[STB]);
		ft_putstr_fd("rr\n", 1);
	}
	else if (type == RRR)
	{
		rrotate(&s[STA]);
		rrotate(&s[STB]);
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	__operator(struct s_stack *s, enum e_type type)
{
	if (type == RA)
	{
		rotate(&s[STA]);
		ft_putstr_fd("ra\n", 1);
	}
	else if (type == RB)
	{
		rotate(&s[STB]);
		ft_putstr_fd("rb\n", 1);
	}
	else if (type == RRA)
	{
		rrotate(&s[STA]);
		ft_putstr_fd("rra\n", 1);
	}
	else if (type == RRB)
	{
		rrotate(&s[STB]);
		ft_putstr_fd("rrb\n", 1);
	}
	else
		__other_operator(s, type);
}

void	operator(struct s_stack *s, enum e_type type)
{
	if (type == SA)
	{
		swap(&s[STA]);
		ft_putstr_fd("sa\n", 1);
	}
	else if (type == SB)
	{
		swap(&s[STB]);
		ft_putstr_fd("sb\n", 1);
	}
	else if (type == PA)
	{
		push(&s[STA], &s[STB]);
		ft_putstr_fd("pa\n", 1);
	}
	else if (type == PB)
	{
		push(&s[STB], &s[STA]);
		ft_putstr_fd("pb\n", 1);
	}
	else
		__operator(s, type);
}
