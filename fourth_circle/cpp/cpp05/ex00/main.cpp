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


#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
			Bureaucrat test("test", 200);
		}
		catch(const std::exception& e)
		{
			std::cerr<< RED << e.what() << RESET << '\n';
		}

		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.decrementGrade();
		b.incrementGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.incrementGrade();
		b.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET<< '\n';
	}
	return (0);
}
