/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:26:38 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:54:42 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_c(struct s_flag *f, va_list ap)
{
	int		count;
	char	ch;
	int		size;

	count = 0;
	size = f->width - 1;
	if (!f->is_minus && f->is_zero)
		count += ft_putchar_fd_iter(1, '0', size);
	else if (!f->is_minus && !f->is_zero && size > 0)
		count += ft_putchar_fd_iter(1, ' ', size);
	if (f->specifer != '%')
		ch = va_arg(ap, int);
	else
		ch = '%';
	count += ft_putchar_fd(ch, 1);
	if (f->is_minus && size > 0)
		count += ft_putchar_fd_iter(1, ' ', size);
	return (count);
}

int	ft_print_s(struct s_flag *f, va_list ap)
{
	char	*str;
	int		lens;
	int		count;
	int		size;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	lens = ft_strlen(str);
	if (!f->is_dot || f->precision > lens || f->precision < 0)
		f->precision = lens;
	size = f->width - f->precision;
	if (!f->is_minus && size > 0 && f->is_zero)
		count += ft_putchar_fd_iter(1, '0', size);
	else if (!f->is_minus && size > 0 && !f->is_zero)
		count += ft_putchar_fd_iter(1, ' ', size);
	count += ft_putstrn_fd(1, str, f->precision);
	if (f->is_minus && size > 0)
		count += ft_putchar_fd_iter(1, ' ', size);
	return (count);
}
