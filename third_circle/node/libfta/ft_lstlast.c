/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:34:03 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/09 20:36:47 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	struct s_list	*ret;

	if (!lst)
		return (NULL);
	ret = lst;
	while (ret->next)
	{
		ret = ret->next;
	}
	return (ret);
}
