/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:10:23 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:55:05 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	ft_plus(struct s_flag *f)
{
	if (f->is_plus)
		return ('+');
	return ('-');
}

static int	__ft_print_nbr(struct s_flag *f, char *nbr, int len)
{
	int		cnt;

	cnt = 0;
	cnt += ft_putchar_fd_iter(1, '0', f->precision - len);
	cnt += ft_putstrn_fd(1, nbr, f->precision);
	return (cnt);
}

static int	ft_print_nbr(struct s_flag *f, char *nbr, char is_neg, int len)
{
	int		cnt;
	int		size;

	cnt = 0;
	size = f->width - f->precision - (f->is_space || is_neg || f->is_plus);
	if ((is_neg || f->is_plus) && (f->is_zero) && *nbr != '-' && !f->is_dot)
		cnt += ft_putchar_fd(ft_plus(f), 1);
	else if (f->is_space && (f->is_zero) && *nbr != '-' && !f->is_dot)
		cnt += ft_putchar_fd(' ', 1);
	if (!f->is_minus && f->is_zero && size > 0 && !f->is_dot)
		cnt += ft_putchar_fd_iter(1, '0', size);
	else if (!f->is_minus && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	if ((is_neg || f->is_plus) && f->is_zero && *nbr != '-' && f->is_dot)
		cnt += ft_putchar_fd(ft_plus(f), 1);
	else if (f->is_space && f->is_zero && *nbr != '-' && f->is_dot)
		cnt += ft_putchar_fd(' ', 1);
	if ((is_neg || f->is_plus) && !f->is_zero && *nbr != '-')
		cnt += ft_putchar_fd(ft_plus(f), 1);
	else if (f->is_space && !(f->is_zero) && *nbr != '-')
		cnt += ft_putchar_fd(' ', 1);
	cnt += __ft_print_nbr(f, nbr, len);
	if (f->is_minus && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	return (cnt);
}

int	ft_print_d_i_u(struct s_flag *f, va_list ap)
{
	char	*nbr;
	long	n;
	char	is_neg;
	int		cnt;

	cnt = 0;
	n = va_arg(ap, int);
	is_neg = (n < 0 && f->specifer != 'u');
	if (is_neg)
		f->is_plus = 0;
	if (n < 0 && f->specifer != 'u')
		n *= -1;
	if (f->specifer == 'u' && n < 0)
		nbr = ft_uitoa(n);
	else
		nbr = ft_itoa(n);
	if (f->precision < (int)ft_strlen(nbr) && !(n == 0 && \
				!f->precision && f->is_dot))
		f->precision = (int)ft_strlen(nbr);
	if (n == 0 && !f->precision && f->is_dot)
		cnt = ft_print_nbr(f, nbr, is_neg, 0);
	else
		cnt = ft_print_nbr(f, nbr, is_neg, ft_strlen(nbr));
	free(nbr);
	return (cnt);
}
