/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:06:43 by joowpark          #+#    #+#             */
/*   Updated: 2023/02/13 11:57:56 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	perror_input(char *file, char *cmd)
{
	write(2, "pipex: ", 7);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	return ;
}

static void	perror_output(void)
{
	exit(1);
}

static void	perror_cmd(char *cmd)
{
	write(2, "pipex: ", 7);
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	else
		write(2, "NULL", 4);
	write(2, ": ", 2);
	write(2, "command not found", 17);
	write(2, "\n", 1);
	exit(127);
}

void	perror_exit(int idx, char *cmd)
{
	if (idx == INPUT_ERR)
		perror_input(cmd, "No such file or directory");
	else if (idx == OUTCMD_ERR)
		perror_cmd(cmd);
	else if (idx == INCMD_ERR)
		perror_cmd(cmd);
	else if (idx == OUTPUT_ERR)
		perror_output();
	else
	{
		if (errno)
			perror(cmd);
		else
		{
			if (cmd)
				ft_putstr_fd(cmd, 2);
			ft_putstr_fd("\n", 2);
		}
		exit(EXIT_FAILURE);
	}
}
