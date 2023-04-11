/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:29:01 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/22 17:54:29 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_flag(struct s_flag *f)
{
	if (f-> specifer == 's')
	{
		if (f->is_zero || f->is_dot || f->is_space)
			return (1);
	}
	return (0);
}

void	init_flag(struct s_flag *flag)
{
	ft_bzero(flag, sizeof(*flag));
}
