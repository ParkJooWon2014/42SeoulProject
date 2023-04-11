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

#ifndef SHURBBERYCREATIONFORM
#define SHURBBERYCREATIONFORM 

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	public : 
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &f);
		ShrubberyCreationForm(string name);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

	public :
		void execute(Bureaucrat const &b) const;
};
#endif /* ifndef SHURBBERYCREATIONFORM */
