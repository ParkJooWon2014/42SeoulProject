/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include "iter.hpp"
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		std::endl << std::endl;

	::iter(a, sizeof(a) / sizeof(char), ft_tolower);

	std::cout << "Changed:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		std::endl << std::endl;

	::iter(a, 2, ft_toupper);
	std::cout << "Changed:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		std::endl << std::endl;
	return (0);
}
