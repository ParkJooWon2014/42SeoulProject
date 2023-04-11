/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:55:48 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/06 15:54:37 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_node.h"

void			ft_init_stack(struct s_stack *stack, struct s_node *node);
struct s_stack	*ft_malloc_stack(struct s_node *node);
void			ft_stack_append(struct s_stack *stack, struct s_node *node);
void			ft_stack_append_init(struct s_stack *s, struct s_node *n);
struct s_node	*ft_stack_pop(struct s_stack *stack);
int				ft_stack_is_empty(struct s_stack *stack);
void			ft_stack_append_tab(struct s_stack *s, int *tabs, int nr_item);
void			swap(struct s_stack *s);
void			push(struct s_stack *a, struct s_stack *b);
void			rotate(struct s_stack *s);
void			rrotate(struct s_stack *s);

#endif
