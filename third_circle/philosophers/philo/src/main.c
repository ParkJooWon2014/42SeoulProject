/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:37:43 by joowpark          #+#    #+#             */
/*   Updated: 2023/02/16 16:12:26 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pthread_create_philo(struct s_philo *p)
{
	int	nr_p;
	int	idx;

	nr_p = p->info->cond[NR_PHILO];
	idx = 1;
	while (idx < nr_p)
	{
		pthread_create(&((p + idx)->thread), NULL, philo_do, p + idx);
		pthread_detach((p + idx)->thread);
		idx += 2;
	}
	idx = 0;
	usleep(p->info->cond[NR_PHILO] * 80);
	while (idx < nr_p)
	{
		pthread_create(&((p + idx)->thread), NULL, philo_do, p + idx);
		if (idx != 0)
			pthread_detach((p + idx)->thread);
		idx += 2;
	}
}

static void	pthread_join_philo(struct s_philo *p)
{
	pthread_join(p->thread, NULL);
}

int	main(int ac, char *av[])
{
	struct s_table	*table;
	struct s_philo	*philos;
	int				idx;

	idx = 0;
	if (ft_init_table(&table, ac, av))
	{
		ft_free_table(table);
		return (0);
	}
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
	pthread_create_philo(philos);
	pthread_join_philo(philos + 0);
	ft_free_philo(philos);
	return (0);
}
