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

#include "Intern.hpp"

Intern::Intern(void){}

Intern::Intern(Intern const &in)
{
	*this = in;
}

Intern::~Intern(void) 
{}

Intern &Intern::operator=(Intern const &in)
{
	(void)in;
	return *this;
}

AForm *Intern::makeForm(string name, string target)
{
	if (name.length() == 0)
		cout<< "FUCK\n";
	AForm *forms[3];

	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);

	// Form 목록중에 존재하는지 확인
	for(int i=0; i<3; i++)
	{
		if (name == forms[i]->getName())
		{
			for (int j = 0 ; j < 3; j ++)
				if (i != j)
					delete forms[j];
			return (forms[i]);
		}
	}
	for (int j = 0 ; j < 3; j ++)
		delete forms[j];

	cout << RED << "There is no form like "  << name << RESET << std::endl;
	return NULL;
}
