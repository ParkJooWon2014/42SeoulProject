/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:14:35 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 12:01:24 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_iter(int fd, char ch, int iter)
{
	int		ret;

	if (iter <= 0)
		return (0);
	ret = 0;
	while (iter --)
		ret += ft_putchar_fd(ch, fd);
	return (ret);
}

int	ft_putstrn_fd(int fd, char *str, int size)
{
	char	*line;
	int		ret;

	ret = 0;
	line = str;
	if (size <= 0)
		return (0);
	while (size -- && *line)
	{
		ret += write(fd, line, 1);
		line += 1;
	}
	return (ret);
}
