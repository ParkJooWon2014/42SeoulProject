/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:48:07 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:08:08 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src, const void *cmp, size_t len)
{
	unsigned char	*s;
	unsigned char	*c;

	s = (unsigned char *)src;
	c = (unsigned char *)cmp;
	while (len --)
	{
		if (*s != *c)
			return (*s - *c);
		s ++;
		c ++;
	}
	return (0);
}
