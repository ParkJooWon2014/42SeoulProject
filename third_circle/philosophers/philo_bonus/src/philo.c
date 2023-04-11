/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:04:14 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:04:58 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(struct s_philo *p, int idx, struct s_table *info)
{
	memset(p, 0, sizeof(*p));
	p->info = info;
	p->forks = info->forks;
	p->idx = idx + 1;
	sem_wait(p->info->nr_eat);
	p->wake_time = get_time();
	p->prv_eat = p->wake_time;
}

static void	philo_think(struct s_philo *p)
{
	if (!ft_philo_is_alive(p))
		return ;
	shout_to_people(p, THINK);
}

static int	philo_sleep(struct s_philo *p)
{
	if (!ft_philo_is_alive(p))
		return (0);
	shout_to_people(p, SLEEP);
	return (ft_philo_usleep(p, p->info->cond[TIME_SLEEP]));
}

static int	philo_eat(struct s_philo *p)
{
	if (ft_philo_pick_fork(p))
		return (1);
	shout_to_people(p, EAT);
	if (ft_philo_usleep(p, p->info->cond[TIME_EAT]))
		return (1);
	p->prv_eat = get_time();
	p->nr_to_eat += 1;
	if (p->info->is_must_eat && p->info->cond[NR_MUST_EAT] == p->nr_to_eat)
		sem_post(p->info->nr_eat);
	sem_post(p->forks);
	sem_post(p->forks);
	return (0);
}

void	*philo_do(void *arg)
{
	struct s_philo	*p;

	p = (struct s_philo *)arg;
	ft_philo_init(p);
	if (p->info->cond[NR_PHILO] == 1)
		shout_to_people(p, INIT_DIE);
	while (ft_philo_is_alive(p))
	{
		if (philo_eat(p))
			break ;
		philo_think(p);
		philo_sleep(p);
	}
	return (NULL);
}
