/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:25:41 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:06:58 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(struct s_philo *p, int idx, struct s_table *info)
{
	memset(p, 0, sizeof(*p));
	p->info = info;
	p->l_fork = info->forks + idx;
	p->r_fork = info->forks + ((idx + 1) % info->cond[NR_PHILO]);
	p->idx = idx + 1;
	p->wake_time = get_time();
	p->prv_eat = p->wake_time;
}

int	__ft_init_table(struct s_table *t)
{
	int		idx;

	idx = 0;
	pthread_mutex_init(&(t->lock), NULL);
	pthread_mutex_init(&(t->guard), NULL);
	pthread_mutex_init(&(t->eat_lock), NULL);
	while (idx < t->cond[NR_PHILO])
	{
		if (pthread_mutex_init(t->forks + idx, NULL))
			return (1);
		idx += 1;
	}
	if (pthread_mutex_init(t->print_lock, NULL))
		return (1);
	t->alive = 1;
	return (0);
}

int	ft_init_table(struct s_table **table, int ac, char *av[])
{
	int				idx;
	struct s_table	*t;

	idx = 0;
	*table = NULL;
	t = malloc(sizeof(*t));
	if (!t)
		return (1);
	*table = t;
	memset(t, 0, sizeof(*t));
	if (ft_parse_input(ac, av + 1, t->cond))
		return (1);
	if (ac == 6)
		t->is_must_eat = 1;
	t->forks = malloc(sizeof(pthread_mutex_t) * t->cond[NR_PHILO]);
	if (!t->forks)
		return (1);
	t->print_lock = malloc(sizeof(pthread_mutex_t));
	if (!t->print_lock)
		return (1);
	if (__ft_init_table(t))
		return (1);
	return (0);
}
