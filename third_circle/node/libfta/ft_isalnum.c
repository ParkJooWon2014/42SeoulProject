/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:16:49 by joowpark          #+#    #+#             */
/*   Updated: 2022/11/09 22:39:52 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	__isalpha(int ch)
{
	return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));
}

static int	__isdigit(int ch)
{
	return ('0' <= ch && ch <= '9');
}

int	ft_isalnum(int ch)
{
	return (__isalpha(ch) || __isdigit(ch));
}
