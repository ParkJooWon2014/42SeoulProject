/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:04:14 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/19 14:52:06 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_timecheck(struct s_philo *p)
{
	return ((get_time() - p->prv_eat) > p->info->cond[TIME_DIE]);
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
	{
		shout_to_people(p, DIE);
		ft_philo_make_dead(p);
		return (1);
	}
	shout_to_people(p, EAT);
	if (ft_philo_usleep(p, p->info->cond[TIME_EAT]))
		return (1);
	p->prv_eat = get_time();
	p->nr_to_eat += 1;
	if (p->info->is_must_eat && p->info->cond[NR_MUST_EAT] == p->nr_to_eat)
		ft_philo_add_nr_eat(p);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
	return (0);
}

void	*philo_do(void *arg)
{
	struct s_philo	*p;

	p = (struct s_philo *)arg;
	if (p->info->cond[NR_PHILO] == 1)
		shout_to_people(p, INIT_DIE);
	while (ft_philo_is_alive(p))
	{
		if (philo_eat(p))
			break ;
		if (p->info->is_must_eat && ft_philo_is_full(p))
		{
			ft_philo_make_dead(p);
			break ;
		}
		philo_think(p);
		if (philo_sleep(p))
			break ;
	}
	return (NULL);
}
