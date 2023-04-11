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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm ("RobotomyRequestForm",72, 45) 
{}

RobotomyRequestForm::RobotomyRequestForm(string name)
	:AForm("RobotomyRequestForm", 72, 45)
{
	target = name;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f)
	:AForm("RobotomyRequestForm", 72, 45)
{
	*this = f;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &f)
{
	this->target = f.getTarget();
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if ((int)b.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::AFormNotSignedException());
	else
	{
		srand(time(NULL));
		if (rand() % 2)
			cout << GREEN << "RobotomyRequestForm Robotomize to" << this->target << "by " << b.getName() << RESET << std::endl;
		else
			cout << RED << "RobotomyRequestForm cannot Robotomize to" << this->target << "by " << b.getName() << RESET << std::endl;
	}
}
