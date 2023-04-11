/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:26:58 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:54:36 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_bonus(char ch, struct s_flag *f)
{
	if (ch == '+')
		f->is_plus = 1;
	if (ch == '#')
		f->is_sharp = 1;
	if (ch == ' ')
		f->is_space = 1;
}

static size_t	ft_parse_width(char *str, va_list ap, struct s_flag *flag)
{
	char	*line;
	char	is_width;

	line = str;
	is_width = 0;
	while (*line && (!ft_strchr(SPECIFIER, *line) && *line != '.'))
	{
		ft_parse_bonus(*line, flag);
		if (*line == '-')
			flag->is_minus = 1;
		if (*line == '0' && !ft_isdigit(*(line - 1)))
			flag->is_zero = 1;
		else if ((!is_width && ft_isdigit(*line)) || *line == '.')
		{
			if (*line == '*')
				flag->width = va_arg(ap, int);
			else
				flag->width = ft_atoi(line);
			is_width = 1;
		}
		line += 1;
	}
	return (line - str);
}

static size_t	ft_parse_precision(char *str, va_list ap, struct s_flag *flag)
{
	char	*line;
	char	is_precision;

	line = str;
	is_precision = 0;
	if (*line != '.')
		return (0);
	line += 1;
	flag->is_dot = 1;
	while (*line && !ft_strchr(SPECIFIER, *line))
	{
		if (!is_precision && (ft_isdigit(*line) || *line == '*'))
		{
			if (*line == '*')
				flag->precision = va_arg(ap, int);
			else
				flag->precision = ft_atoi(line);
			is_precision = 1;
		}
		line += 1;
	}
	return (line - str);
}

int	ft_parse_print(char	**line, va_list ap)
{
	char			*str;
	struct s_flag	flag;

	str = *line;
	init_flag(&flag);
	str += ft_parse_width(str, ap, &flag);
	str += ft_parse_precision(str, ap, &flag);
	flag.neg_prec = flag.precision < 0;
	flag.specifer = *str;
	*line = str;
	return (ft_print_format(&flag, ap));
}
