/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:51:50 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/07 16:04:22 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

struct s_node	*ft_pop_front(struct s_node **root)
{
	*root = (*root)->nxt;
	return (ft_pop_back(root));
}

int	ft_is_node_empty(struct s_node *node)
{
	return (node == NULL);
}

struct s_node	*ft_find_node(struct s_node *node, int num)
{
	struct s_node	*tmp;

	if (!node)
		return (node);
	if (node->number == num)
		return (node);
	tmp = node->nxt;
	while (node != tmp)
	{
		if (tmp->number == num)
			return (tmp);
		tmp = tmp->nxt;
	}
	return (NULL);
}
