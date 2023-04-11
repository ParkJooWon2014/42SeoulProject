/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:19:30 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 15:12:26 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	struct s_list	*tmp;

	tmp = lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp -> next;
	}
}
