/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:50:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/09 11:07:31 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char			check;
	struct s_stack	stack[2];

	if (ac <= 1)
		return (0);
	ft_init_stack(&stack[STB], NULL);
	ft_init_stack(&stack[STA], NULL);
	ft_parse_stack(ac, av, &stack[STA], &check);
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_is_sort(&stack[STA]))
		return (0);
	do_push_swap(stack);
	ft_free_stack(stack);
	return (0);
}
