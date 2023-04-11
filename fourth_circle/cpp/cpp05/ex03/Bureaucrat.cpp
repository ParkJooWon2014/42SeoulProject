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
#include "AForm.hpp"

Bureaucrat::Bureaucrat(string const &name): name(name), grade(75){};
Bureaucrat::Bureaucrat(string const &name, int grade) :name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(void) :name("NO NAME"), grade(75){}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}catch(std::exception &e)
	{
		cout << YELLOW <<this->name << " couldn’t execute "  << form.getName() << 
			" bucause " << e.what() << RESET << std::endl;
		return ;
	}
	cout << BOLDWHITE << name << " executed " << form.getName() << RESET << std::endl;
}

string Bureaucrat::getName(void) const 
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->grade < 2)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->grade > 149)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		cout << YELLOW <<this->name << " couldn’t sign "  << form.getName() << 
			" bucause " << e.what() << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &s, const Bureaucrat &b)
{
	s << b.getName() << ", bureaucrat grade " << b.getGrade();
	return s;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high...";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low...";
}
