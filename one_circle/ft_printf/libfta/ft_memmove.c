/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:54 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:02:48 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (len && !dst && !src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (dst <= src)
	{
		while (len --)
			*d ++ = *s ++;
	}
	else
	{
		d += len;
		s += len;
		while (len --)
			*--d = *--s;
	}
	return (dst);
}
