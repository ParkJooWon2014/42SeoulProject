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

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <time.h>
#include <stdlib.h>

Base::~Base(void){};

Base * generate(void)
{
	int choice;

	choice = rand() % 3;
	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else 
		return (new C());
}

void identify(Base* p)
{
	std::cout << GREEN ;
	if (dynamic_cast<A *>(p))
		std::cout << "This is A Type" << RESET<< std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "This is B Type" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "This is C Type" << RESET << std::endl;
	else
		std::cout << "This is Wrong Type" << RESET <<std::endl;
}

void identify(Base& p)
{
	std::cout << BLUE ;
	for (int i = 0 ; i < 3 ; i ++)
	{
		try
		{
			if (i == 0){
				Base &unused = dynamic_cast<A &>(p);
				(void)unused;
				std::cout << "This is A Type" << RESET << std::endl;
				return ;
			}else if (i == 1){
				Base &unused = dynamic_cast<B &>(p);
				std::cout << "This is B Type" << RESET <<std::endl;
				(void)unused;
				return ;
			}
			else if (i == 2){
				Base &unused = dynamic_cast<C &>(p);
				std::cout << "This is C Type" << RESET << std::endl;
				(void)unused;
				return ;
			}
			else
				std::cout << "There is somethign wrong" << RESET<< std::endl;
		}
		catch (std::exception &e)
		{
			continue;
		}
	}
	std::cout << "Wrong Base !" << RESET <<std::endl;
}
