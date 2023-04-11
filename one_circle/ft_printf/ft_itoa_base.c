/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:47:30 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/19 11:51:52 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nbrlen(uint64_t n, unsigned int base)
{
	size_t	ret;

	ret = 0;
	while (n)
	{
		n /= base;
		ret += 1;
	}
	if (ret == 0)
		return (1);
	return (ret);
}

char	*ft_itoa_base(uintptr_t n, unsigned int nr_base, char is_x)
{
	char	*ret;
	int		nbr_len;
	char	*base;

	if (is_x)
		base = SBASE;
	else
		base = LBASE;
	nbr_len = nbrlen(n, nr_base);
	ret = (char *)malloc(sizeof(*ret) * (nbr_len + 1));
	if (!ret)
		return (ret);
	*(ret + nbr_len) = 0;
	while (nbr_len --)
	{
		*(ret + nbr_len) = base[n % nr_base];
		n /= nr_base;
	}
	return (ret);
}
