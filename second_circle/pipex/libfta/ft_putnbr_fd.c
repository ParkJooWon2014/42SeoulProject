/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punbr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:44:40 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/09 19:45:16 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	num;
	char	str[100];
	int		cnt;

	num = nb;
	cnt = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	while (num)
	{
		str[cnt++] = num % 10 + '0';
		num /= 10;
	}
	while (cnt -- > 0)
	{
		write(fd, str + cnt, 1);
	}
}
