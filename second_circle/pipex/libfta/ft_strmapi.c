/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:26:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 12:37:36 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		lens;
	char		*aloc;
	char const	*tmp;
	char		*pc;

	tmp = s;
	lens = ft_strlen(tmp);
	aloc = (char *)malloc(sizeof(*aloc) * (lens + 1));
	if (!aloc)
		return (aloc);
	pc = aloc;
	while (*tmp)
	{
		*pc = f(tmp - s, *tmp);
		pc ++;
		tmp ++;
	}
	*pc = '\0';
	return (aloc);
}
