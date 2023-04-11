/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:07:03 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/19 18:21:09 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

int	ft_philo_timecheck(struct s_philo *p)
{
	return ((get_time() - p->prv_eat) > p->info->cond[TIME_DIE]);
}

void	shout_to_people(struct s_philo *p, int type)
{
	char		*msg;
	long long	time;

	time = get_time();
	sem_wait(p->info->print_lock);
	if (type == EAT)
		msg = "is eating";
	else if (type == FORK)
		msg = "has taken a fork";
	else if (type == SLEEP)
		msg = "is sleeping";
	else if (type == THINK)
		msg = "is thinking";
	else
		msg = "died";
	if (type == INIT_DIE)
	{
		sem_post(p->info->print_lock);
		shout_to_people(p, FORK);
		ft_philo_usleep(p, p->info->cond[TIME_DIE]);
		ft_philo_make_dead(p);
		time = get_time();
	}
	printf("%lld_in_ms %d %s\n", time - p->wake_time, p->idx, msg);
	sem_post(p->info->print_lock);
}

int	ft_philo_pick_fork(struct s_philo *p)
{
	if (sem_wait(p->forks))
		return (1);
	if (ft_philo_timecheck(p))
	{
		sem_post(p->forks);
		return (1);
	}
	shout_to_people(p, FORK);
	if (sem_wait(p->forks))
	{
		sem_post(p->forks);
		return (1);
	}
	shout_to_people(p, FORK);
	if (ft_philo_timecheck(p))
	{
		sem_post(p->forks);
		sem_post(p->forks);
		return (1);
	}
	return (0);
}

int	ft_philo_usleep(struct s_philo *p, long long ms)
{
	long long	begin;
	long long	end;
	int			ret;

	ret = 0;
	begin = get_time();
	end = begin + ms;
	while (1)
	{
		if (get_time() >= end)
			break ;
		if (!ft_philo_is_alive(p))
			break ;
		if (ft_philo_timecheck(p))
		{
			shout_to_people(p, DIE);
			ft_philo_make_dead(p);
			return (1);
		}
		usleep(50);
	}
	return (0);
}
