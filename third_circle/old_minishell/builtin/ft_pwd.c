/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjo <tjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:54:38 by tjo               #+#    #+#             */
/*   Updated: 2022/12/29 16:33:56 by tjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_builtin_header.h"

int	pwd(char **s)
{
	char	*ret;

	(void)s;
	ret = getcwd(NULL, 0);
	if (ret == 0)
		return (error_handling("pwd", 0, 0));
	ft_printf("%s\n", ret);
	free(ret);
	return (0);
}
