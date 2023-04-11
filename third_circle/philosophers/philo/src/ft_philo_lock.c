/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:50 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/19 14:44:29 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_philo_is_alive(struct s_philo *p)
{
	int	ret;

	pthread_mutex_lock(&(p->info->lock));
	ret = p->info->alive;
	pthread_mutex_unlock(&(p->info->lock));
	return (ret);
}

void	ft_philo_make_dead(struct s_philo *p)
{
	pthread_mutex_lock(&(p->info->lock));
	p->info->alive = false;
	pthread_mutex_unlock(&(p->info->lock));
}

void	ft_philo_add_nr_eat(struct s_philo *p)
{
	pthread_mutex_lock(&(p->info->eat_lock));
	p->info->nr_least_eat += 1;
	pthread_mutex_unlock(&(p->info->eat_lock));
}

int	ft_philo_is_full(struct s_philo *p)
{
	int	check;

	pthread_mutex_lock(&p->info->eat_lock);
	check = (p->info->nr_least_eat >= p->info->cond[NR_PHILO]);
	pthread_mutex_unlock(&p->info->eat_lock);
	return (check);
}
