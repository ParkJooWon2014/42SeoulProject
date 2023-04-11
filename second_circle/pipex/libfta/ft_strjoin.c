/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:24:56 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/05 11:44:45 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*__strcat(char *dest, char const *src)
{
	char	*tmp;

	if (!dest || !src)
		return (NULL);
	tmp = dest;
	while (*tmp)
	{
		tmp++;
	}
	while (1)
	{
		*tmp = *src;
		if (!*tmp)
			break ;
		tmp ++;
		src ++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	lens;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(*ret) * (lens + 1));
	if (!ret)
		return (ret);
	*ret = '\0';
	__strcat(ret, s1);
	__strcat(ret, s2);
	ret[lens] = '\0';
	return (ret);
}
