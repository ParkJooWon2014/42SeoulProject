/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:22:13 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:55:14 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_pointer(struct s_flag *f, char *nbr, int lenn)
{
	int		cnt;
	int		size;

	cnt = 0;
	if (!f->is_dot || f->precision < lenn)
		f->precision = lenn;
	size = f->width - f->precision;
	cnt += write(1, "0x", 2 * f->is_zero);
	size -= 2;
	if (!f->is_minus && !f->is_zero && !f->is_dot && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	else if (!f->is_minus && f->is_zero && size > 0)
		cnt += ft_putchar_fd_iter(1, '0', size);
	cnt += write(1, "0x", 2 * !f->is_zero);
	cnt += ft_putstr_fd(nbr, 1);
	if (f->is_minus && size > 0)
		cnt += ft_putchar_fd_iter(1, ' ', size);
	return (cnt);
}

int	ft_print_p(struct s_flag *f, va_list ap)
{
	uintptr_t	p;
	char		*nbr;
	int			cnt;

	cnt = 0;
	p = va_arg(ap, uintptr_t);
	nbr = ft_itoa_base(p, 16, 1);
	if (!nbr)
		return (-1);
	cnt = ft_print_pointer(f, nbr, ft_strlen(nbr));
	free(nbr);
	return (cnt);
}
