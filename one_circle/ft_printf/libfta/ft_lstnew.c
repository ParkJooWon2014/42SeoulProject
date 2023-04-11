/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:05:42 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/09 20:33:00 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*ret;

	ret = (struct s_list *)malloc(sizeof(*ret));
	if (!ret)
		return (ret);
	*ret = (struct s_list)
	{
		.content = content,
		.next = NULL,
	};
	return (ret);
}
