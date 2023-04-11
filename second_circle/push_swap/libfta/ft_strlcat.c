/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:40:58 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 15:24:25 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	char			*tmp;
	unsigned int	dsize;
	unsigned int	ssize;
	unsigned int	ret;

	tmp = dest;
	dsize = ft_strlen(tmp);
	ssize = ft_strlen(src);
	ret = dsize + ssize;
	if (size <= dsize)
		return (ssize + size);
	tmp += dsize;
	size -= dsize;
	if (ssize >= size)
		ssize = size - 1;
	ft_memcpy(tmp, src, ssize);
	tmp[ssize] = '\0';
	return (ret);
}
