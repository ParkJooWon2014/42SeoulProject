/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:39 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:00:57 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	__isspace(char c)
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

int	ft_atoi(const char *str)
{
	long	ret;
	char	is_minus;
	char	*tmp;

	tmp = (char *)str;
	is_minus = 0;
	ret = 0;
	while (__isspace(*tmp))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp++ == '-')
			is_minus = !is_minus;
	}
	while ('0' <= *tmp && *tmp <= '9')
	{
		ret *= 10;
		ret += *tmp - '0';
		tmp ++;
	}
	if (is_minus)
		ret *= -1;
	return (ret);
}
