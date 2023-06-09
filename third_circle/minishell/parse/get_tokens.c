/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:57:30 by joowpark          #+#    #+#             */
/*   Updated: 2023/03/27 11:20:52 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include"../builtin/ft_builtin_header.h"

static size_t	ft_sstrlen(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*tmp)
		tmp ++;
	return (tmp - strs);
}

static int	__do_node(struct s_node *root)
{
	int		ret;
	int		is_in_pipe;
	size_t	idx;

	idx = 0;
	ret = 0;
	is_in_pipe = 0;
	search_tree(root, &is_in_pipe, &ret);
	while (idx ++ < root->depth)
		waitpid(-1, NULL, 0);
	return (ret);
}

static void	__get_tokens(struct s_node **tree)
{
	int	cnt;

	cnt = 0;
	while (*tree)
	{
		cnt++;
		if ((*tree)->line && ft_strncmp((*tree)->line, "&&", 3) == 0)
		{
			if (g_exit_code)
				tree ++;
			tree ++;
			continue ;
		}
		else if ((*tree)->line && ft_strncmp((*tree)->line, "||", 3) == 0)
		{
			if (!g_exit_code)
				tree ++;
			tree ++;
			continue ;
		}
		__do_node(*tree);
		tree ++;
	}
	if (cnt != 1)
		exit_code_export(g_exit_code);
}

static void	get_tokens_other(struct s_node **trees, size_t len)
{
	trees[len - 1] = NULL;
	__get_tokens(trees);
	free_trees(trees);
}

int	get_tokens(char *cmd, int ret, size_t idx)
{
	struct s_node	**trees;
	size_t			len;
	char			**tokens;
	char			**toks;

	tokens = parse_tokens(cmd);
	if (!tokens)
		return (1);
	toks = tokens;
	len = ft_sstrlen(tokens) + 1;
	trees = (struct s_node **)malloc(sizeof(*trees) * len);
	if (!trees)
		return (1);
	while (*tokens && !ret)
	{
		trees[idx] = get_tree(*tokens ++);
		if (!trees[idx])
			break ;
		pre_search_tree(trees[idx ++], &ret);
	}
	free_tokens(toks);
	if (ret)
		return (ret);
	return (get_tokens_other(trees, len), 0);
}
