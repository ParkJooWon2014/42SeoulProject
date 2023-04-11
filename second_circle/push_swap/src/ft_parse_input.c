/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:06:30 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/09 11:10:04 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*__ft_line_to_ints(int *tab, char **lines)
{
	char	**tmps;
	char	check;

	tmps = lines;
	while (*tmps)
	{
		check = 1;
		tab[tmps - lines] = ft_atoi(*tmps, &check);
		if (check)
			break ;
		tmps += 1;
	}
	if (check)
		ft_free(2, &tab, &lines);
	else
		ft_free(1, &lines);
	return (tab);
}

int	*ft_line_to_ints(char *line, int *nr_count)
{
	char	**lines;
	int		*tab;

	*nr_count = 0;
	lines = ft_parse(line, nr_count);
	if (!lines)
		return (NULL);
	tab = (int *)malloc(sizeof(*tab) * (*nr_count));
	if (!tab)
	{
		free(lines);
		return (tab);
	}
	return (__ft_line_to_ints(tab, lines));
}

static void	ft_check_dup(struct s_stack *s, char *check)
{
	size_t			idx;
	struct s_node	*node;
	struct s_node	*begin;
	int				number;

	idx = 0;
	begin = s->bottom;
	while (idx++ < s->size)
	{
		number = begin->number;
		node = begin->nxt;
		while (node != s->bottom)
		{
			if (number == node->number)
				*check = 1;
			node = node->nxt;
		}
		if (*check)
			break ;
		begin = begin->nxt;
	}
}

int	ft_is_sort(struct s_stack *s)
{
	int				check;
	struct s_node	*node;

	node = s->bottom->nxt;
	check = 1;
	while (node != s->bottom)
	{
		if (node->prv->number < node->number)
			check = 0;
		if (!check)
			return (check);
		node = node->nxt;
	}
	return (check);
}

void	ft_parse_stack(int ac, char **av, struct s_stack *s, char *check)
{
	int	idx;
	int	*tab;
	int	nr_count;

	idx = 1;
	while (idx < ac)
	{
		tab = ft_line_to_ints(av[idx], &nr_count);
		if (!tab)
		{
			*check = 1;
			break ;
		}
		if (!nr_count)
		{
			*check = 1;
			break ;
		}
		ft_stack_append_tab(s, tab, nr_count);
		idx += 1;
		free(tab);
	}
	if (!*check && nr_count)
		ft_check_dup(s, check);
}
