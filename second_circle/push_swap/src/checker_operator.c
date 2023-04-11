/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:10:12 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 15:08:28 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__other_coperator(struct s_stack *s, enum e_type type)
{
	if (type == SS)
	{
		swap(&s[STA]);
		swap(&s[STB]);
	}
	else if (type == RR)
	{
		rotate(&s[STA]);
		rotate(&s[STB]);
	}
	else if (type == RRR)
	{
		rrotate(&s[STA]);
		rrotate(&s[STB]);
	}
}

static void	__coperator(struct s_stack *s, enum e_type type)
{
	if (type == RA)
	{
		rotate(&s[STA]);
	}
	else if (type == RB)
	{
		rotate(&s[STB]);
	}
	else if (type == RRA)
	{
		rrotate(&s[STA]);
	}
	else if (type == RRB)
	{
		rrotate(&s[STB]);
	}
	else
		__other_coperator(s, type);
}

void	coperator(struct s_stack *s, enum e_type type)
{
	if (type == SA)
	{
		swap(&s[STA]);
	}
	else if (type == SB)
	{
		swap(&s[STB]);
	}
	else if (type == PA)
	{
		push(&s[STA], &s[STB]);
	}
	else if (type == PB)
	{
		push(&s[STB], &s[STA]);
	}
	else
		__coperator(s, type);
}
