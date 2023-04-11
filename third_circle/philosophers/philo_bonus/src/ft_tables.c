/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:25:41 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:07:18 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static sem_t	*ft_sem_open(char *str, int num)
{
	sem_t	*sem;

	sem = sem_open(str, O_CREAT | O_EXCL, 0644, num);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(str);
	return (sem_open(str, O_CREAT | O_EXCL, 0644, num));
}

int	__ft_init_table(struct s_table *t)
{
	t->print_lock = ft_sem_open(PRINT, 1);
	t->moniter = ft_sem_open(MONI, 1);
	if (t->is_must_eat)
		t->nr_eat = ft_sem_open(MUST_EAT, t->cond[NR_PHILO]);
	if (t->moniter == SEM_FAILED || t->print_lock == SEM_FAILED
		|| t->nr_eat == SEM_FAILED)
		return (1);
	t->forks = ft_sem_open(FORKS, t->cond[NR_PHILO]);
	if (t->forks == SEM_FAILED)
		return (1);
	t->alive = 1;
	return (0);
}

int	ft_init_table(struct s_table **table, int ac, char *av[])
{
	struct s_table	*t;

	t = malloc(sizeof(*t));
	*table = NULL;
	if (!t)
		return (1);
	*table = t;
	memset(t, 0, sizeof(*t));
	if (ft_parse_input(ac, av + 1, t->cond))
		return (1);
	if (ac == 6)
		t->is_must_eat = 1;
	if (__ft_init_table(t))
		return (1);
	return (0);
}
