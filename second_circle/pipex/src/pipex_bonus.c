/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:59:27 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/05 12:26:07 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_path(char **path, int in, int out)
{
	while (*path)
		free((*path)++);
	if (in > 1)
		close(in);
	close(out);
}

static void	__here_doc(int *fd, char *limiter)
{
	char	*str;

	close(fd[0]);
	dup2(fd[1], 1);
	while (1)
	{
		str = get_next_line(0);
		if (!str || ft_strncmp(str, limiter, ft_strlen(limiter)) == 0
			|| ft_strlen(str) - 1 == ft_strlen(limiter))
			break ;
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
	close(fd[1]);
	exit(0);
}

static void	here_doc(int *outfile, char *file, char *limiter)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < -1)
		perror_exit(-1, "Invalid pipi");
	pid = fork();
	if (pid == -1)
		perror_exit(-1, "Invalid fork");
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(pid, NULL, WNOHANG);
	}
	else
		__here_doc(fd, limiter);
	*outfile = ft_open_file(file, O_RDWR | O_CREAT | O_APPEND);
	if (*outfile == -1)
		perror_exit(OUTPUT_ERR, "");
	dup2(*outfile, 1);
}

static void	mand(int *infile, int *outfile, int ac, char *av[])
{
	*infile = ft_open_file(av[1], O_RDONLY);
	if (*infile != -1)
		dup2(*infile, 0);
	else
		perror_exit(INPUT_ERR, av[1]);
	*outfile = ft_open_file(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC);
	if (*outfile == -1)
		perror_exit(OUTPUT_ERR, "");
}

int	main(int ac, char *av[], char *envp[])
{
	int		infile;
	int		outfile;
	char	**paths;
	int		idx;

	if (ac < 5)
		perror_exit(-1, "Invalid argument");
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		infile = -2;
		here_doc(&outfile, av[ac - 1], av[2]);
		idx = 3;
	}
	else
	{
		mand(&infile, &outfile, ac, av);
		idx = 2;
	}
	paths = ft_get_paths(envp);
	while (idx < (ac - 2))
		redir(av[idx++], paths, envp, infile != -1);
	dup2(outfile, 1);
	exec_cmd(av[idx], paths, envp, OUT);
	free_path(paths, infile, outfile);
	return (0);
}
