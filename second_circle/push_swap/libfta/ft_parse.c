/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:59:44 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/06 12:44:08 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_change_cmd_del(char *cmd, char *is)
{
	*cmd = 0;
	*is = 1;
}

static void	ft_change_cmd_not_del(char **ret, char *cmd, int *nr, char *is)
{
	if (*is)
	{
		ret[*nr] = cmd;
		*nr = *nr + 1;
	}
	*is = 0;
}

char	**ft_parse(char *cmd, int *nr_tokens)
{
	char	**ret;
	char	is_word;

	is_word = 1;
	*nr_tokens = 0;
	ret = malloc(sizeof(*ret) * (ft_strlen(cmd)));
	if (!ret)
		return (ret);
	while (*cmd)
	{
		if (ft_isspace(*cmd))
			ft_change_cmd_del(cmd, &is_word);
		else
			ft_change_cmd_not_del(ret, cmd, nr_tokens, &is_word);
		cmd += 1;
	}
	ret[*nr_tokens] = NULL;
	return (ret);
}
