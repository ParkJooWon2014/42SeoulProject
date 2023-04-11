/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:31:06 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/09 10:18:24 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

void	ft_free(int nr, ...)
{
	va_list	ap;
	void	**data;

	va_start(ap, nr);
	while (nr --)
	{
		data = va_arg(ap, void **);
		free(*data);
		*data = NULL;
	}
}

static void	ft_free_node(struct s_node *node)
{
	struct s_node	*prv;
	struct s_node	*now;

	if (!node)
		return ;
	now = node->nxt;
	free(node);
	while (now != node)
	{
		prv = now;
		now = now->nxt;
		free(prv);
	}
}

void	ft_free_stack(struct s_stack *s)
{
	ft_free_node(s[STA].bottom);
	ft_free_node(s[STB].bottom);
}
