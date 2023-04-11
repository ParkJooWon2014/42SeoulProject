/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:53:42 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/06 17:25:32 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

# include "types.h"

struct s_node	*ft_malloc_node(int number);
void			ft_append_back(struct s_node **root, struct s_node *new);
void			ft_append_front(struct s_node **root, struct s_node *new);
struct s_node	*ft_pop_back(struct s_node **root);
struct s_node	*ft_pop_front(struct s_node **root);
int				ft_is_node_empty(struct s_node *node);
void			ft_print_node(struct s_node *root);
struct s_node	*ft_find_node(struct s_node *node, int num);
#endif 
