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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm ("PresidentialPardonForm",25, 5) 
{}

PresidentialPardonForm::PresidentialPardonForm(string name)
	:AForm("PresidentialPardonForm", 25, 5)
{
	target = name;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f)
	:AForm("PresidentialPardonForm", 25, 5)
{
	*this = f;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &f)
{
	this->target = f.getTarget();
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if ((int)b.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::AFormNotSignedException());
	else
		cout << GREEN << this->target << " has been pardoned by Zaphod Beeblebrox." << RESET <<std::endl;
}
