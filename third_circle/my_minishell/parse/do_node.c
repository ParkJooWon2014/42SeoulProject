/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:43:15 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/09 18:11:01 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_strslen(char **cmd)
{
	char	**tmp;

	tmp = cmd;
	while (*tmp)
		tmp ++;
	return (tmp - cmd);
}

static struct s_node *get_node(char **tokens)
{
	struct s_node	*root;
	int				ret;

	ret = 0;
	if (!ft_strncmp(*tokens, "||", 3) || !ft_strncmp(*tokens, "&&", 3))
		return (ft_alloc_node( *tokens,ROOT, NULL));
	root = ft_alloc_node("|", PIPE, NULL);
	if (!root)
		return (NULL);
	while (*tokens)
	{
		if (astree_insert_node(root, *tokens, get_type(*tokens)))
			ret = 1;
		if (ret)
			break ;
		tokens += 1;
	}
	if (ret)
	{
		perror(NULL);
		return (ret);
	}
	return (root);
}

static struct s_node	*__get_tree(char *cmd)
{
	char			**tokens;
	int				nr_tokens;
	char			*new_cmd;
	int				ret;
	struct s_node	*root;

	ret = 1;
	new_cmd = line_env_expender(cmd);
	tokens = malloc(sizeof(*tokens) * (ft_strlen(new_cmd) + 1));
	if (!tokens)
		return (NULL);
	if (!parse_cmd(tokens, new_cmd, &nr_tokens))
		root = get_node(tokens);
	free_tokens(tokens);
	free(new_cmd);
	return (root);
}

static int do_pre_search_tree(struct s_node **node)
{
	int	ret;
	
	ret = 0;
	while (*node)
	{
		pre_search_tree(node, &ret);
		node += 1;
		if (ret)
			break ;
	}
	return (ret);
}

static void do_serach_node(struct s_node **tree)
{
	int	cmd_fail;

	cmd_fail = 1;
	while (*tree)
	{
		if ((*tree)->line && ft_strncmp((*tree)->line, "&&", 3) == 0)
		{
			if (cmd_fail)
				tree ++;
			tree ++;
			continue ;
		}
		else if ((*tree)->line && ft_strncmp((*tree)->line, "||", 3) == 0)
		{
			if (!cmd_fail)
				tree ++;
			tree += 1;
			continue ;
		}
		cmd_fail = __do_node(*tree);
		tree += 1;
	}
}

static void	do_node(char **cmd)
{
	int				cmd_fail;
	struct s_node	**tree;
	size_t			idx;

	idx = 0;
	node = (struct s_node **)malloc(sizeof(*node) * ft_strslen(cmd));
	if (!node)
		return ;
	while (*cmd)
	{
		tree[idx ++] = __get_tree(*cmd);
		cmd += 1;
	}
	do_pre_search_tree(tree);
	do_search_tree(tree);
}
