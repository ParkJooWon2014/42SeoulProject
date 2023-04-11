/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:43 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/13 15:48:43 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin_header.h"

static int	get_check_line(struct s_node *node, int *fd)
{
	if (!node->parent || !node->parent->left || !node->parent->left->left \
		|| ft_strncmp(node->parent->left->left->line, "<<", 2) == 0 \
		|| !node->parent->left->here_doc || pipe(fd) < 0)
		return (1);
	return (0);
}

void	get_input_line(struct s_node *node, int is_in_pipe)
{
	int		fd[2];
	char	*line;
	pid_t	pid;

	(void)is_in_pipe;
	if (get_check_line(node, fd))
		return ;
	line = node->parent->left->here_doc;
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		write(fd[1], line, ft_strlen(line));
		close(fd[1]);
		exit(0);
	}
}
