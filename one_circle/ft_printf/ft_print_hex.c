/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:29:47 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 16:11:16 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sharp(struct s_flag *f)
{
	if (f->specifer == 'x')
		return (write(1, "0x", 2));
	if (f->specifer == 'X')
		return (write(1, "0X", 2));
	return (0);
}

static int	ft_print_hex(struct s_flag *f, char *nbr, int n, int len)
{
	int		cnt;
	int		size;

	cnt = 0;
	if (f->precision < len)
		f->precision = len;
	if (f->is_sharp && n)
		f->width -= 2;
	size = f->width - f->precision;
	if (f->is_sharp && f->is_zero && n && !f->is_dot)
		cnt += ft_sharp(f);
	if (!f->is_minus && f->is_zero && size > 0 && !f->is_dot)
		cnt += ft_putchar_fd_iter(1, '0', size);
	else if (!f->is_minus && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	if (f->is_sharp && n && (f->is_dot || !f->is_zero))
		cnt += ft_sharp(f);
	cnt += ft_putchar_fd_iter(1, '0', f->precision - len);
	if (len != 0)
		cnt += ft_putstr_fd(nbr, 1);
	if (f->is_minus && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	return (cnt);
}

int	ft_print_x_x(struct s_flag *f, va_list ap)
{
	int		n;
	char	*nbr;
	int		cnt;

	cnt = 0;
	n = va_arg(ap, int);
	nbr = ft_itoa_base((unsigned)n, 16, f->specifer == 'x');
	if (!nbr)
		return (-1);
	if (n == 0 && f->is_dot && !f->precision)
		cnt += ft_print_hex(f, nbr, n, 0);
	else
		cnt += ft_print_hex(f, nbr, n, ft_strlen(nbr));
	free(nbr);
	return (cnt);
}

/*
*/
