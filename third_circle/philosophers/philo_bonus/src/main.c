/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:37:43 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:03:54 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	process_create_philo(struct s_philo *p)
{
	int	nr_p;
	int	idx;

	nr_p = p->info->cond[NR_PHILO];
	idx = 0;
	while (idx < nr_p)
	{		
		p[idx].pid = fork();
		if (p[idx].pid == 0)
		{
			philo_do(p + idx);
			exit(0);
		}
		idx += 1;
	}
}

static void	process_wait_philo(struct s_philo *p, pthread_t *thread)
{
	int	idx;
	int	nr_p;

	nr_p = p->info->cond[NR_PHILO];
	idx = 0;
	sem_wait(p->info->moniter);
	pthread_create(thread, NULL, ft_moniter, p);
	if (p->info->is_must_eat)
		pthread_create(thread + 1, NULL, ft_philo_must_eat, p);
	pthread_detach(thread[1]);
	while (idx < nr_p)
	{
		waitpid(p[idx].pid, NULL, 0);
		idx += 1;
	}
	pthread_join(*thread, NULL);
}

int	main(int ac, char *av[])
{
	struct s_table	*table;
	struct s_philo	*philos;
	int				idx;
	pthread_t		thread[2];

	idx = 0;
	if (ft_init_table(&table, ac, av))
		return (ft_free_table(table));
	philos = malloc(sizeof(*philos) * table->cond[NR_PHILO]);
	if (!philos)
	{
		ft_free_table(table);
		return (0);
	}
	while (idx < table->cond[NR_PHILO])
	{
		ft_init_philo(philos + idx, idx, table);
		idx ++;
	}
	process_create_philo(philos);
	process_wait_philo(philos, thread);
	ft_free_philo(philos);
	return (0);
}
