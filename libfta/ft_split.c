/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:39:18 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/28 11:00:11 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**strs_copy(char **tokens, int nr_tokens)
{
	char	**tmp;
	int		idx;

	idx = 0;
	tmp = (char **)malloc(sizeof(*tmp) * (nr_tokens));
	if (!tmp)
		return (NULL);
	while (tokens[idx])
	{
		tmp[idx] = ft_strdup(tokens[idx]);
		idx ++;
	}
	free(tokens);
	tmp[idx] = NULL;
	return (tmp);
}

char	**__ft_split(char **ret, char *line, char c)
{
	char	is_word;
	int		nr_tokens;

	is_word = 1;
	nr_tokens = 0;
	while (*line)
	{
		if (*line != c)
		{
			if (is_word)
			{
				ret[nr_tokens] = line;
				nr_tokens += 1;
			}
			is_word = 0;
		}
		else
		{
			*line = '\0';
			is_word = 1;
		}
		line ++;
	}
	ret[nr_tokens ++] = NULL;
	return (strs_copy(ret, nr_tokens));
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*line;

	ret = (char **)malloc(sizeof(*ret) * (ft_strlen(s) + 1));
	if (!ret)
		return (ret);
	line = ft_strdup(s);
	if (!line)
		return (NULL);
	ret = (__ft_split(ret, line, c));
	free(line);
	return (ret);
}
