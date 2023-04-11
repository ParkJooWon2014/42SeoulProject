/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:56:27 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/05 16:25:43 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdlib.h>
# include "../libfta/libft.h"

# define INIT_PRIORITY -1

struct s_node{
	struct s_node	*prv;
	struct s_node	*nxt;
	int				number;
	int				priority;
};

struct s_stack{
	struct s_node	*bottom;
	struct s_node	*top;
	size_t			size;
};

#endif
