/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:32:00 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 13:46:27 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				ret;
	struct s_list	*tmp;

	tmp = lst;
	ret = 0;
	while (lst)
	{
		lst = lst->next;
		ret += 1;
	}
	return (ret);
}
