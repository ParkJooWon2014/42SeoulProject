/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:46:52 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:46:54 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
