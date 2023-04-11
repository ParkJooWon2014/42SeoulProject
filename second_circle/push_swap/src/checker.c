/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:38:24 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/09 11:28:55 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_exit(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(0);
}

static int	ft_get_cmd_type(char *line, char *check)
{
	char	**types;
	int		idx;

	types = (char *[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	idx = 0;
	while (idx < 11)
	{
		if (ft_strncmp(types[idx], line, ft_strlen(line)) == 0)
			return (idx);
		idx += 1;
	}
	*check = 1;
	return (-1);
}

static void	do_checker(struct s_stack *s, char *check)
{
	char	*line;
	int		type;

	*check = 0;
	ft_indx_nodes(s + STA);
	while (1)
	{
		line = get_next_line(0);
		if (!line || !*line)
			break ;
		if (ft_strlen(line) <= 1 || ft_strlen(line) > 4)
			*check = 1;
		line[ft_strlen(line) - 1] = 0;
		type = ft_get_cmd_type(line, check);
		free(line);
		if (*check)
			break ;
		coperator(s, type);
	}
	if (*check)
		print_exit("Error\n", 2);
	else
		free(line);
}

int	main(int ac, char *av[])
{
	char			check;
	struct s_stack	stack[2];

	if (ac <= 1)
		return (0);
	ft_init_stack(&stack[STB], NULL);
	ft_init_stack(&stack[STA], NULL);
	ft_parse_stack(ac, av, &stack[STA], &check);
	if (check)
		print_exit("Error\n", 2);
	do_checker(stack, &check);
	if (ft_is_sort(&stack[STA]) && stack[STB].size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(stack);
	return (0);
}
