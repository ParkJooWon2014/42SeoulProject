/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:30:26 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/16 20:36:04 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	ft_parse_input(int ac, char *lines[], int *cond)
{
	int		idx;
	char	check;

	check = 0;
	memset(cond, 0, sizeof(*cond));
	idx = 0;
	if (!(ac == 5 || ac == 6))
		return (1);
	while (idx < ac - 1)
	{
		cond[idx] = ft_atoi(lines[idx], &check);
		if (check || cond[idx] <= 0)
			return (1);
		idx += 1;
	}
	return (0);
}
