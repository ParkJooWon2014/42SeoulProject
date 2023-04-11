/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:49:42 by joowpark          #+#    #+#             */
/*   Updated: 2023/02/07 14:50:33 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:38:57 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/16 17:41:07 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_file(char *path, int flag)
{
	int		fd;

	fd = open(path, flag, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}

char	**ft_get_paths(char *envp[])
{
	char			**lines;
	extern char		**environ;

	if (!envp || !(*envp))
		envp = environ;
	lines = envp;
	while (*lines)
	{
		if (ft_strncmp(*lines, "PATH", 4) == 0)
			return (ft_split(*lines + 5, ':'));
		lines += 1;
	}
	return (NULL);
}

static char	*ft_get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!access(cmd, 0))
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (cmd);
}

int	exec_cmd(char *cmd, char **paths, char **envp, int type)
{
	char		*cmd_line;
	char		**cmds;

	cmds = ft_parse(cmd);
	if (!cmds)
		perror_exit(type, cmd);
	cmd_line = ft_get_cmd(paths, *cmds);
	execve(cmd_line, cmds, envp);
	perror_exit(type, cmd_line);
	return (-1);
}

int	redir(char *cmd, char **paths, char **envp, int fd)
{
	int		pipetube[2];
	pid_t	pid;

	if (pipe(pipetube) < 0)
		perror_exit(-1, "Invalid pipe");
	pid = fork();
	if (pid)
	{
		close(pipetube[1]);
		dup2(pipetube[0], 0);
		waitpid(pid, NULL, WNOHANG);
		close(pipetube[0]);
	}
	else
	{
		close(pipetube[0]);
		dup2(pipetube[1], 1);
		close(pipetube[1]);
		if (fd == 0)
			exit(1);
		else
			return (exec_cmd(cmd, paths, envp, INCMD_ERR));
	}
	return (1);
}
