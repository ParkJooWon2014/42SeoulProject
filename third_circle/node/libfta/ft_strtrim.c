/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:04 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 16:57:07 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	size_t		front;
	size_t		rear;
	char		dict[256];

	ft_bzero((void *)dict, sizeof(dict));
	front = 0;
	ret = NULL;
	rear = ft_strlen(s1) - 1;
	while (*set)
		dict[(int)*set++] = 1;
	if (s1 && set)
	{
		while (*(s1 + front) && dict[(int)*(s1 + front)])
			front ++;
		while (*(s1 + rear) && dict[(int)*(s1 + rear)] && (front < rear))
			rear --;
		ret = (char *)malloc(sizeof(*ret) * (rear - front + 2));
		if (ret)
			ft_strlcpy(ret, (char *)s1 + front, rear - front + 2);
	}
	return (ret);
}
