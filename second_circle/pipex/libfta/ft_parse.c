/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:59:44 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/05 15:37:19 by joowpark         ###   ########.fr       */
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

static void	incre_gal(char **ch, int *is_gal)
{
	if (**ch == '{')
		*is_gal = *is_gal + 1;
	else if (**ch == '}')
		*is_gal = *is_gal - 1;
	else if (**ch == '\\')
		**ch = ' ';
}

static int	__ft_parse(char **ret, char **line, int *nr_tokens, char del)
{
	int		cnt;
	char	is_word;
	int		is_gal;

	is_word = 1;
	cnt = 0;
	is_gal = 0;
	while (**line)
	{
		if (**line == del && is_gal == 0)
		{
			ft_change_cmd_del(*line, &is_word);
			cnt += 1;
		}
		else if (**line != del && is_gal == 0)
			ft_change_cmd_not_del(ret, *line, nr_tokens, &is_word);
		if (cnt == 2)
			break ;
		incre_gal(line, &is_gal);
		(*line) += 1;
	}
	if (cnt < 2)
		*nr_tokens -= 1;
	return (cnt < 2);
}

char	**ft_parse(char *cmd)
{
	char	**ret;
	char	is_word;
	int		nr_tokens;

	is_word = 1;
	nr_tokens = 0;
	ret = malloc(sizeof(*ret) * (ft_strlen(cmd)));
	if (!ret)
		return (ret);
	while (*cmd)
	{
		if (ft_isspace(*cmd))
			ft_change_cmd_del(cmd, &is_word);
		else if (*cmd == '\'' || *cmd == '\"')
		{
			if (__ft_parse(ret, &cmd, &nr_tokens, *cmd))
				break ;
			is_word = 1;
		}
		else
			ft_change_cmd_not_del(ret, cmd, &nr_tokens, &is_word);
		cmd += 1;
	}
	ret[nr_tokens] = NULL;
	return (ret);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "awk \"{count++} END {printf \\\"count: %i\\\", count }\"";
	char **tmp = ft_parse(str);
	for(; *tmp; tmp += 1)
		printf("%s\n",*tmp);
	return (0);
}
*/
