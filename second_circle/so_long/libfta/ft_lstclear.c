/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:57:56 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 14:43:27 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	struct s_list	*tmp;
	struct s_list	*free_node;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		free_node = tmp;
		tmp = tmp->next;
		ft_lstdelone(free_node, del);
	}
	*lst = NULL;
}
