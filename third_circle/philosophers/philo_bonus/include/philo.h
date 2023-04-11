/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:27:11 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/22 12:04:27 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "types.h"

# define LOCK "lock"
# define PRINT "print"
# define MONI "moniter"
# define MUST_EAT "must_eat"
# define FORKS "p_forks"

enum e_type
{
	NR_PHILO,
	TIME_DIE,
	TIME_EAT,
	TIME_SLEEP,
	NR_MUST_EAT,
	EAT,
	FORK,
	SLEEP,
	THINK,
	DIE,
	INIT_DIE,
};

struct s_table
{
	bool				is_must_eat;
	int					cond[5];
	sem_t				*forks;
	sem_t				*print_lock;
	sem_t				*lock;
	bool				alive;
	int					nr_wake;
	int					nr_least_eat;
	sem_t				*nr_eat;
	sem_t				*moniter;
};

struct s_philo
{
	pid_t			pid;
	int				idx;
	long long		prv_eat;
	long long		wake_time;
	sem_t			*forks;
	int				nr_to_eat;
	struct s_table	*info;
};

void		*ft_philo_must_eat(void *arg);
void		ft_philo_init(struct s_philo *p);
void		ft_philo_kill(struct s_philo *p);
void		*ft_moniter(void *arg);
int			ft_philo_is_full(struct s_philo *p);
void		ft_philo_add_nr_eat(struct s_philo *p);
void		ft_philo_make_dead(struct s_philo *p);
bool		ft_philo_is_alive(struct s_philo *p);
void		ft_free_philo(struct s_philo *p);
int			ft_free_table(struct s_table *t);
void		*philo_do(void *arg);
long long	get_time(void);
int			ft_parse_input(int ac, char *line[], int *cond);
int			ft_philo_timecheck(struct s_philo *p);
void		shout_to_people(struct s_philo *p, int type);
int			ft_philo_pick_fork(struct s_philo *p);
int			ft_init_table(struct s_table **t, int ac, char *av[]);
void		ft_init_philo(struct s_philo *p, int idx, struct s_table *info);
int			ft_philo_usleep(struct s_philo *p, long long ms);
#endif
