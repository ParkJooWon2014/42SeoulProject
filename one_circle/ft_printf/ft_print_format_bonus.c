/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:13:48 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:54:50 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_format(struct s_flag *flag, va_list ap)
{
	int		count;

	count = 0;
	if (flag->specifer == 'c' || flag->specifer == '%')
		count = ft_print_c(flag, ap);
	else if (flag->specifer == 'd' || flag->specifer == 'u' \
			|| flag->specifer == 'i')
		count = ft_print_d_i_u(flag, ap);
	else if (flag->specifer == 's')
		count = ft_print_s(flag, ap);
	else if (flag->specifer == 'x' || flag->specifer == 'X')
		count = ft_print_x_x(flag, ap);
	else if (flag->specifer == 'p')
		count = ft_print_p(flag, ap);
	return (count);
}
