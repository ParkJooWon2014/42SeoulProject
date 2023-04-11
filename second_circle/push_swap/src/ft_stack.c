/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:54:36 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/06 15:54:05 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	ft_init_stack(struct s_stack *stack, struct s_node *node)
{
	size_t	cnt;

	cnt = 1;
	if (!node)
	{
		stack->bottom = NULL;
		stack->size = 0;
		return ;
	}
	stack->bottom = node;
	node = node->nxt;
	while (node != stack->bottom)
		cnt ++;
	stack->top = node->prv;
	stack->size = cnt;
}

void	ft_stack_append_init(struct s_stack *stack, struct s_node *node)
{
	if (!(stack -> bottom))
	{
		stack->bottom = node;
		stack->top = node;
		stack->size = 1;
		return ;
	}
	ft_append_front(&(stack->bottom), node);
	stack->bottom = node;
	stack->size += 1;
}

void	ft_stack_append(struct s_stack *stack, struct s_node *node)
{
	if (!(stack -> bottom))
	{
		stack->bottom = node;
		stack->top = node;
		stack->size = 1;
		return ;
	}
	ft_append_back(&(stack->bottom), node);
	stack->top = node;
	stack->size += 1;
}

struct s_node	*ft_stack_pop(struct s_stack *stack)
{
	struct s_node	*pop;

	stack->top = stack->top->prv;
	pop = ft_pop_back(&(stack->bottom));
	if (!pop)
		return (pop);
	stack->size -= 1;
	return (pop);
}

int	ft_stack_is_empty(struct s_stack *stack)
{
	return (stack->size == 0);
}
/*
struct s_stack	*ft_malloc_stack(struct s_node *node)
{
	struct s_stack	*stack;
	size_t			cnt;

	cnt = 1;
	stack = (struct s_stack *)malloc(sizeof(*stack));
	if (!stack)
		return (stack);
	ft_init_stack(stack, node);
	return (stack);
}
*/
