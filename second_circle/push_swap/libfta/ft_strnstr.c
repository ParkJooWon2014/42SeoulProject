/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:27:14 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:37:36 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*src;
	size_t	lens;

	lens = ft_strlen(needle);
	src = (char *)haystack;
	if (!*needle)
		return ((char *)haystack);
	while (len && *src && (size_t)(src - haystack) + lens <= len)
	{
		if (ft_memcmp(src, needle, lens) == 0)
			return (src);
		src ++;
	}
	return (NULL);
}
