/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:50:06 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/05 16:23:43 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>

struct s_node	*__ft_malloc_node(int number, int priority)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(*node));
	if (!node)
		return (node);
	*node = (struct s_node){
		.prv = node,
		.nxt = node,
		.number = number,
		.priority = priority,
	};
	return (node);
}

struct s_node	*ft_malloc_node(int number)
{
	return (__ft_malloc_node(number, INIT_PRIORITY));
}

void	ft_append_back(struct s_node **root, struct s_node *new)
{
	struct s_node	*back;

	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	back = (*root)->prv;
	back->nxt = new;
	new->prv = back;
	new->nxt = *root;
	(*root)->prv = new;
}

void	ft_append_front(struct s_node **root, struct s_node *new)
{
	ft_append_back(root, new);
	*root = new;
}

struct s_node	*ft_pop_back(struct s_node **root)
{
	struct s_node	*pop;
	struct s_node	*tmp;

	if (!*root)
		return (*root);
	tmp = (*root)->prv;
	(*root)->prv = tmp->prv;
	(*root)->prv->nxt = *root;
	pop = __ft_malloc_node(tmp->number, tmp->priority);
	if (!pop)
		return (pop);
	if (*root == tmp)
	{
		free(*root);
		*root = NULL;
	}
	else
		free(tmp);
	return (pop);
}
