/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:32:03 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/27 18:24:44 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <ctype.h>

inline string idx_to_str(int idx)
{
	string sets[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	if (idx > 4)
		return ("FUCK YOU");
	return sets[idx];
}

string	add_spaces(int n)
{
	string	str;

	while (n--)
		str.append(" ");
	return (str);
}

string	fix_width(string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void Contact::printFormat(int idx)
{
	string str = "0"; str[0] += idx;
	cout << "|" << add_spaces(10 - str.size()) << str;
	str = fix_width(this->info[FIRST], 10);
	cout << "|" << add_spaces(10 - str.size()) << str;
	str = fix_width(this->info[LAST], 10);
	cout << "|" << add_spaces(10 - str.size()) << str;
	str = fix_width(this->info[NICK], 10);
	cout << "|" << add_spaces(10 - str.size()) << str;
	cout << "|" << std::endl;	
}

void Contact::print(void)
{
	for (int i = 0 ; i < NR_INFO; i++)
		cout << idx_to_str(i) << ": " << this->info[i] << std::endl;
}

static int isAllDigit(string &data)
{
	for (size_t i = 0 ; i < data.length(); i ++)
	{
		if (!isdigit(data[i]))
			return (0);
	}
	return (1);
}

int Contact::set_info(int type, string data)
{
	if (data.length() == 0)
		return (1);
	if (type == PHONENUM)
	{
		if (isAllDigit(data))
			this->info[PHONENUM] = data;
		else
			return (1);
	}
	this->info[type] = data;
	return (0);
}
