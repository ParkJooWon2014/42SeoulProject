/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:59:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 14:36:00 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	ret;
	unsigned int	len;

	ret = ft_strlen(src);
	if (size)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (ret);
}
