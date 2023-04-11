/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:27:59 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/16 16:35:10 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

char		*ft_itoa(int n);
int			ft_atoi(const char *tmp, char *check);
#endif
