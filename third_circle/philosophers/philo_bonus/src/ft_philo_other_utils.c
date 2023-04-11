/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:50 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/19 14:46:35 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_philo_is_alive(struct s_philo *p)
{
	int	ret;

	ret = p->info->alive;
	return (ret);
}

void	ft_philo_make_dead(struct s_philo *p)
{
	p->info->alive = false;
	sem_post(p->info->moniter);
}

void	*ft_philo_must_eat(void *arg)
{
	int				idx;
	struct s_philo	*p;

	p = (struct s_philo *)arg;
	idx = 0;
	while (idx ++ < p->info->cond[NR_PHILO])
		sem_wait(p->info->nr_eat);
	sem_post(p->info->moniter);
	return (NULL);
}

void	ft_philo_init(struct s_philo *p)
{
	if (p->idx % 2)
		usleep(p->info->cond[NR_PHILO] * 100);
}
