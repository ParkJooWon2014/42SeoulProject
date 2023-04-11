/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:07:03 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/19 14:46:02 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

void	shout_to_people(struct s_philo *p, int type)
{
	char		*msg;
	long long	time;

	time = get_time();
	pthread_mutex_lock(p->info->print_lock);
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
		pthread_mutex_unlock(p->info->print_lock);
		shout_to_people(p, FORK);
		ft_philo_usleep(p, p->info->cond[TIME_DIE]);
		ft_philo_make_dead(p);
		time = get_time();
	}
	printf("%lld_in_ms %d %s\n", time - p->wake_time, p->idx, msg);
	pthread_mutex_unlock(p->info->print_lock);
}

int	ft_philo_pick_fork(struct s_philo *p)
{
	if (pthread_mutex_lock(p->l_fork))
		return (1);
	if (ft_philo_timecheck(p))
	{
		pthread_mutex_unlock(p->l_fork);
		return (1);
	}
	shout_to_people(p, FORK);
	if (pthread_mutex_lock(p->r_fork))
	{
		pthread_mutex_unlock(p->l_fork);
		return (1);
	}
	shout_to_people(p, FORK);
	if (ft_philo_timecheck(p))
	{
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(p->l_fork);
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

void	ft_philo_wait_guard(struct s_philo *p)
{
	int	check;

	check = 0;
	while (1)
	{
		pthread_mutex_lock(&(p->info->guard));
		if (p->info->nr_guard == p->info->cond[NR_PHILO] / 2)
			check = 1;
		pthread_mutex_unlock(&(p->info->guard));
		if (check)
			break ;
	}
}
