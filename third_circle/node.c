/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:03:16 by joowpark          #+#    #+#             */
/*   Updated: 2023/03/24 11:24:25 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

struct s_node	*node_alloc(int type, char *line)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(*node));
	if (!node)
		return (node);
	ft_bzero(node, sizeof(*node));
	node->type = type;
	node->line = line;
	return (node);
}

struct s_node	*node_back(struct s_node *root)
{
	struct s_node	*node;

	if (!root)
		return (NULL);
	node = root;
	while (node->nxt)
		node = node->nxt;
	return (node);
}

int	node_append_back(struct s_node **root, struct s_node *new)
{
	struct s_node *node;

	if (!*root)
	{
		*root = new;
		return (0);
	}
	node = node_back(*root);
	node->nxt = new;
	return (0);
}

int	node_append_front(struct s_node **root, struct s_node *new)
{
	struct s_node *node;
	
	if (!*root)
	{
		*root = new;
		return (0);
	}
	new->nxt = *root;
	*root = new;
}

struct s_node *node_find(struct s_node *root, size_t idx)
{
	struct s_node	*node;

	if (!root)
		return (NULL);
	node = *root;
	while (node)
	{
		if (node->idx == idx)
			return (node);
		node = node->nxt;
	}
	return (node);
}

int	node_del(struct s_node **root, size_t idx)
{
	struct s_node *prv;
	struct s_node *now;
	struct s_node *nxt;

	if (!*root)
		return (NULL);

}
