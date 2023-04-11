/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_moniter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:29:36 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/16 18:29:05 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_kill(struct s_philo *p)
{
	sem_post(p->info->moniter);
}

void	*ft_moniter(void *arg)
{
	struct s_philo	*p;
	int				idx;

	p = (struct s_philo *)arg;
	idx = 0;
	sem_wait(p->info->moniter);
	while (idx < p->info->cond[NR_PHILO])
	{
		kill(p[idx].pid, SIGKILL);
		idx += 1;
	}
	return (NULL);
}
