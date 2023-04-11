/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:05:23 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/18 17:24:37 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	__swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	__reverse(char *s)
{
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(s);
	if (!right)
		return ;
	right -= 1;
	while (left < right)
		__swap(s + left ++, s + right --);
}

static void	__ft_uitoa(char *tmp, unsigned long ln)
{
	while (ln)
	{
		*tmp ++ = (ln % 10) + '0';
		ln /= 10;
	}
	*tmp = 0;
}

static size_t	size_number(unsigned long ln)
{
	size_t	ret;

	ret = 1;
	if (!ln)
		return (2);
	if (ln < 0)
	{
		ln *= -1;
		ret ++;
	}
	while (ln)
	{
		ln /= 10;
		ret ++;
	}
	return (ret);
}

char	*ft_uitoa(unsigned int n)
{
	char			*ret;
	char			*tmp;
	unsigned long	ln;

	ln = (unsigned long)n;
	ret = (char *)malloc(sizeof(*ret) * (size_number(ln)));
	if (!ret)
		return (ret);
	tmp = ret;
	if (ln == 0)
		*tmp++ = '0';
	if (ln < 0)
	{
		ln *= -1;
		*tmp++ = '-';
	}
	__ft_uitoa(tmp, ln);
	__reverse(tmp);
	return (ret);
}
