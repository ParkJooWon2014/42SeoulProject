/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:57:30 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/09 18:06:35 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t ft_sstrlen(char **strs)
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
	//new_cmd = line_env_expender(cmd);
	search_tree(root, &is_in_pipe, &ret);
	while (idx ++ < root->depth)
		waitpid(-1, NULL, 0);
	return (ret);
}


void print_node(struct s_node *node)
{
	if (node && node->line)
		printf("[%s]\n",node->line);
	if (node->left)
		print_node(node->left);
	if (node->right)
		print_node(node->right);
}


static int __get_tokens(struct s_node **tree)
{
	int	cmd_fail;
	//static int cnt;
	cmd_fail = 0;
	
	while (*tree)
	{
	//	printf("+++++++++++%d++++++++\n" ,cnt++);
	//	print_node(*tree);
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
		//printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		tree += 1;
	}
	return (0);
}

int	get_tokens(char *cmd)
{
	struct s_node	**trees;
	size_t			len;
	size_t			idx;
	char			**tokens;
	int				ret;

	tokens = parse_tokens(cmd); //tokens -> && || [ls -al] [&&] cat
	if (!tokens)
		return (1);
	idx = 0;
	ret = 0;
	len = ft_sstrlen(tokens) + 1;
	trees = (struct s_node **)malloc(sizeof(*trees) * len);
	if (!trees)
		return (1);
	while (*tokens)
	{
		trees[idx] = get_tree(*tokens ++);
		if (!trees[idx])
			break ;
		pre_search_tree(trees[idx], &ret);
		if (ret)
			return (ret);
		idx ++;
	}
	free_tokens(tokens - idx);
	trees[len] = NULL;
	//return (0);
	return (__get_tokens(trees));
}
