/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:26:18 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:16:19 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (ret);
	ft_strlcpy(ret, src, len + 1);
	return (ret);
}
