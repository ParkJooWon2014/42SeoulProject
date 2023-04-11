/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:20:36 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/31 12:26:51 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook:: PhoneBook(void)
{
	this->idx = 0;
	this->size = 0;
	cout <<  "HI I AM PHONEBOOK\n";
}

PhoneBook::~PhoneBook(void)
{
	cout << "Bye Bye\n";
}

int PhoneBook:: add(void)
{
	int	idx = 0;
	string data;
	Contact &contact = this->contact[this->idx];
	while(idx < NR_INFO)
	{
		data = "";
		cout <<"write " << idx_to_str(idx)  << " :";
		if (!getline(cin, data) && cin.eof())
			return (1);
		if (contact.set_info(idx, data))
		{
			cout << "Your input is wrong" << std::endl;
			continue ;
		}
		idx += 1;
	}
	this->idx = ((this->idx + 1) % 8);
	if (this->size < 8)
		this->size += 1;
	return (0);
}

int PhoneBook:: search(void)
{
	string data = "";

	if (!this->size)
		return (1);
	cout << " ___________________________________________ " << std::endl;
	cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0 ; i < this->size; i ++)
		this->contact[i].printFormat(i + 1);
	cout << "Write you get :"; 
	if (!getline(cin, data) || trim(data) == "")
		return (1);
	trim(data);
	if (data.length() != 1 || data[0] < '0' || data[0] > '9')
		return (1);
	this->contact[(int)(data[0] - '0' - 1)].print();
	return (0);
}

int PhoneBook::exit(void)
{
	return (1);
}
