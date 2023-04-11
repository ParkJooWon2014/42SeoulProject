/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:45:58 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 13:11:15 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*line;
	int		ret;
	int		tmp;

	ret = 0;
	line = (char *)format;
	va_start(ap, format);
	while (*line)
	{
		if (*line == '%')
		{
			line += 1;
			tmp = ft_parse_print(&(line), ap);
			if (tmp == -1)
				return (tmp);
			ret += tmp;
		}
		else
			ret += ft_putchar_fd(*line, 1);
		line += 1;
	}
	va_end(ap);
	return (ret);
}
