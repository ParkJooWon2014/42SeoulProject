/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:54:16 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/05 16:48:51 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include "../libfta/libft.h"
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define BUFFER_SIZE 1
# define INCMD_ERR 0
# define OUTCMD_ERR 1
# define INPUT_ERR 2
# define OUTPUT_ERR 3
# define IN 0
# define OUT 1

void	perror_exit(int idx, char *cmd);
int		exec_cmd(char *cmd, char **paths, char **envp, int type);
char	*get_next_line(int fd);
int		exec_cmd(char *cmd, char **paths, char **envp, int type);
int		redir(char *cmd, char **paths, char **envp, int fd);
int		ft_open_file(char *path, int flag);
char	**ft_get_paths(char *envp[]);
char	**ft_parse(char *cmd);

#endif
