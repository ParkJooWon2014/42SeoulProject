/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:58:11 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/27 20:50:44 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;

	while (1)
	{
		string cmd;
		cout << "INPUT CMD (ADD, SEARCH, EXIT): " ;
		if (!std::getline(cin, cmd) || cin.eof())
			break ;
		trim(cmd);
		if (cmd == "ADD")
		{
			if (book.add() && book.exit())
				break ;
		}
		else if (cmd == "SEARCH")
		{
			if (book.search())
				cout << "NOTHING IN BOOK"  << std::endl;
		}
		else if (cmd == "EXIT")
		{
			if (book.exit())
				break ;
		}
		else 
			cout << "Your cmd is Xhit!" << std::endl;
	}
	return (0);
}
