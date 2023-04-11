/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:09:45 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/31 12:19:04 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for(int j = 0; j < (int)strlen(av[i]); j ++)
			putchar(toupper(av[i][j]));
	}
	putchar('\n');
	return (0);
}
