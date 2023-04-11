/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:35:51 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:04:11 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__ft_free_table(struct s_table *t)
{
	if (t->moniter)
		sem_unlink(MONI);
	if (t->nr_eat)
		sem_unlink(MUST_EAT);
	if (t->print_lock)
		sem_unlink(PRINT);
	if (t->lock)
		sem_unlink(LOCK);
	free(t);
}

int	ft_free_table(struct s_table *t)
{
	sem_close(t->forks);
	sem_unlink(FORKS);
	__ft_free_table(t);
	return (0);
}

void	ft_free_philo(struct s_philo *p)
{
	ft_free_table(p->info);
	free(p);
}
