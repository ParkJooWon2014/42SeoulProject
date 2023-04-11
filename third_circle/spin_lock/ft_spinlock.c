/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spin_lock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:13:08 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/20 13:35:46 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct s_spinlock {
	int	lock;
};

struct s_spinlock lock;

void	ft_spin_init(struct s_spinlock *lock)
{
	lock->lock = 0;
}

static int	compare_and_swap(int *value, int old, int new)
{
	__asm__	volatile ("lock ; cmpxchg %3, %1"
			: "=a"(old), "=m"(*value)
			: "a"(old), "r"(new)
			: "memory" );
	return (old);
}

int	ft_spin_lock(struct s_spinlock *lock)
{
	while ((compare_and_swap(&(lock->lock), 0, -1) == -1))
			;
	return (1);
}

int	ft_spin_unlock(struct s_spinlock *lock)
{
	lock->lock = 0;
	return (0);
}

/*
int cnt= 0 ;

void *thread(void *arg)
{
	int id = *(int *)arg;

	for(int i = 0 ; i < 100 ; i ++)
	{
		ft_spin_lock(&lock);
		cnt += 1;
		printf("%d : %d\n",id ,cnt);
		ft_spin_unlock(&lock);
	}
	return NULL;

}

int main()
{
	pthread_t pt[NR_THREAD];
	for (int i = 0 ; i <NR_THREAD; i ++ )
	{
		int idx = i ;
		pthread_create(pt + i, NULL,thread, &idx);
	}
	for (int i = 0 ; i < NR_THREAD; i ++)
		pthread_join(pt[i], NULL);
	return (0);
}
*/
