/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:11:18 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/20 13:15:14 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

#include <unist.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

#define NR_INFO 6
enum e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
};

struct s_map
{
	char	*info[NR_INFO];
	char	**map;

};

#endif
