/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:55 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 11:09:32 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	ch;

	tmp = (char *)s;
	ch = (char)c;
	while (*tmp)
	{
		if (*tmp == (ch))
			return (tmp);
		tmp ++;
	}
	if (*tmp == ch)
		return (tmp);
	return (NULL);
}
