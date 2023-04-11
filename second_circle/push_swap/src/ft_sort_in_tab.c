/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:22:57 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/04 11:47:29 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int *arr, size_t length)
{
	unsigned int	i;
	unsigned int	piv;

	if (length <= 1)
		return ;
	piv = 0;
	i = 0;
	while (i < length)
	{
		if (arr[i] < arr[length -1])
		{
			__swap(arr + i, arr + piv);
			piv ++;
		}
		i ++;
	}
	__swap(arr + piv, arr + length -1);
	quicksort(arr, piv++);
	quicksort(arr + piv, length - piv);
}

static int	*ft_stack_to_ints(struct s_stack *s)
{
	int				*tab;
	struct s_node	*node;
	size_t			idx;

	idx = 0;
	tab = (int *)malloc(sizeof(*tab) * (s->size));
	if (!tab)
		return (tab);
	node = s->bottom;
	while (idx < s->size)
	{
		tab[idx] = node->number;
		node = node->nxt;
		idx += 1;
	}
	quicksort(tab, s->size);
	return (tab);
}

void	ft_indx_nodes(struct s_stack *s)
{
	int				*tab;
	size_t			idx;
	int				number;
	struct s_node	*node;

	tab = ft_stack_to_ints(s);
	if (!tab)
		return ;
	idx = 0;
	while (idx < s->size)
	{
		number = tab[idx];
		node = ft_find_node(s->bottom, number);
		node->priority = idx;
		idx ++;
	}
	free(tab);
}
