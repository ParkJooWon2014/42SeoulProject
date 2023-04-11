/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:05:23 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 19:06:23 by joowpark         ###   ########.fr       */
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

void	__ft_itoa(char *tmp, long ln)
{
	while (ln)
	{
		*tmp ++ = (ln % 10) + '0';
		ln /= 10;
	}
	*tmp = 0;
}

size_t	size_number(long ln)
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

char	*ft_itoa(int n)
{
	char	*ret;
	char	*tmp;
	long	ln;

	ln = (long)n;
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
	__ft_itoa(tmp, ln);
	__reverse(tmp);
	return (ret);
}
