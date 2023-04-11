/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:51 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:06:37 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_table(struct s_table *t)
{
	int	idx;

	idx = 0;
	if (t->forks)
	{
		while (idx < t->cond[NR_PHILO])
		{
			pthread_mutex_destroy(t->forks + idx);
			idx += 1;
		}
		free(t->forks);
	}
	if (t->print_lock)
	{
		pthread_mutex_destroy(t->print_lock);
		free(t->print_lock);
	}
	if (t)
		free(t);
}

void	ft_free_philo(struct s_philo *p)
{
	ft_free_table(p->info);
	free(p);
}
