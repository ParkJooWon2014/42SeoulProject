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

#ifndef EASYFIND_HPP
#define EASYFIND_HPP 

#include <iostream>
#include <algorithm>

class NotFoundExecption : public std::exception
{
	public :
		virtual const char *what() const throw()
		{
				return ("Not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator iter = find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NotFoundExecption();
	return (iter);
};

#endif /* ifndef EASYFIND_HPP */
