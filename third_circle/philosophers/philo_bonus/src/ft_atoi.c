/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:39 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/16 17:28:07 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	__isspace(char c)
{
	char	*str;

	str = " \t\n\v\f\r";
	while (*str)
	{
		if (*str == c)
			return (1);
		str ++;
	}
	return (0);
}

static void	is_in_range(long num, char is_minus, char *check)
{
	if (is_minus == -1)
		num *= -1;
	if (num < INT_MIN || num > INT_MAX)
		*check = 1;
}

int	ft_atoi(const char *tmp, char *check)
{
	long	ret;
	int		is_minus;

	is_minus = 1;
	ret = 0;
	while (__isspace(*tmp))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp++ == '-')
			is_minus *= -1;
	}
	while ('0' <= *tmp && *tmp <= '9')
	{
		*check = 0;
		ret *= 10;
		ret += *tmp++ - '0';
		is_in_range(ret, is_minus, check);
	}
	if (*tmp && !*check)
		*check = 1;
	else if (!*check && !*tmp)
		*check = 0;
	return (ret * is_minus);
}
