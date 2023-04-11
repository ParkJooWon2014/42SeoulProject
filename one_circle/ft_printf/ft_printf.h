/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:19:12 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 16:51:25 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "./libfta/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

# define SPECIFIER "cspdiuxX%"
# define LBASE "0123456789ABCDEF"
# define SBASE "0123456789abcdef"

struct s_flag
{
	char	is_zero;
	char	is_minus;
	char	is_dot;
	char	is_sharp;
	char	is_space;
	char	is_plus;
	char	neg_prec;
	int		width;
	int		precision;
	char	specifer;
};
int		ft_putstrn_fd(int fd, char *str, int size);
int		ft_printf(const char *format, ...);
int		ft_putchar_fd_iter(int fd, char ch, int iter);
void	init_flag(struct s_flag *flag);
int		ft_print_format(struct s_flag *flag, va_list ap);
int		ft_print_c(struct s_flag *f, va_list ap);
int		ft_print_d_i_u(struct s_flag *f, va_list ap);
int		ft_print_s(struct s_flag *f, va_list ap);
int		ft_print_format(struct s_flag *flag, va_list ap);
int		ft_check_flag(struct s_flag *f);
int		ft_print_x_x(struct s_flag *f, va_list ap);
int		ft_parse_print(char	**line, va_list ap);
char	*ft_itoa_base(uintptr_t n, unsigned int nr_base, char is_x);
int		ft_print_p(struct s_flag *f, va_list ap);
int		ft_print_format(struct s_flag *flag, va_list ap);
#endif
