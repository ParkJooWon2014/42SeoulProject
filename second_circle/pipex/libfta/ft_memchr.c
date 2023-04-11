/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:47:34 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/09 22:21:27 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	if (!len)
		return (NULL);
	while (len --)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp ++;
	}
	return (NULL);
}
