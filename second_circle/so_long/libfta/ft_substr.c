/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 14:49:58 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	char	*ret;

	if (!s)
		return ((char *)s);
	lens = ft_strlen(s);
	if (lens < len)
		len = lens;
	if (!lens || lens <= start)
		return (ft_calloc(1, 1));
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (ret);
	ft_strlcpy(ret, (char *)s + start, len + 1);
	return (ret);
}
