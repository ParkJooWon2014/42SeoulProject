/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:49:20 by joowpark          #+#    #+#             */
/*   Updated: 2023/02/13 11:56:12 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_path(char **path)
{
	while (*path)
		free((*path)++);
}

int	main(int ac, char *av[], char *envp[])
{
	int		infile;
	int		outfile;
	char	**paths;

	if (ac != 5)
		perror_exit(-1, "Invalid argument");
	infile = ft_open_file(av[1], O_RDONLY);
	if (infile != -1)
		dup2(infile, 0);
	else
		perror_exit(INPUT_ERR, av[1]);
	paths = ft_get_paths(envp);
	if (!paths)
		return (1);
	redir(av[2], paths, envp, infile != -1);
	outfile = ft_open_file(av[4], O_RDWR | O_CREAT | O_TRUNC);
	if (outfile == -1)
		perror_exit(OUTPUT_ERR, "");
	dup2(outfile, 1);
	exec_cmd(av[3], paths, envp, IN);
	close(infile);
	close(outfile);
	free_path(paths);
	return (0);
}
