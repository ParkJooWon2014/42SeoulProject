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

#include "Form.hpp"

Form::Form(void): name("No Name"), isSigned(false), requiredGradeToSign(10), requiredGradeToExecute(100) {}

Form::Form(string const &name): name(name), isSigned(false), requiredGradeToSign(10), requiredGradeToExecute(100) {}

Form::Form(string const &name, int execGrade, int signGrade): name(name), isSigned(false), requiredGradeToSign(signGrade), requiredGradeToExecute(execGrade) {}

Form::Form(int sign, int exec): name("No Name"), isSigned(false), requiredGradeToSign(sign), requiredGradeToExecute(exec)
{
	if (sign > 150 || exec > 150)
		throw(Form::GradeTooLowException());
	if (sign < 1 || sign < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form(void){}

string Form::getName(void) const
{
	return this->name;
}

string Form::isSignedS(void) const
{
	if (this->isSigned)
		return "SIGNED!";
	else
		return "NO SIGNED";
}

bool Form::getSigned(void) const
{
	return this->isSigned;
}

int Form::getSignGrade(void) const
{
	return this->requiredGradeToSign;
}

int Form::getExecGrade(void) const
{
	return this->requiredGradeToSign;
}

std::ostream &operator<<(std::ostream &s, Form const &f)
{
	s << "FORM : "<< f.getName() << " " << f.isSignedS() << " and required grad : " << f.getSignGrade() <<
		" and exec grade " << f.getExecGrade();
	return s;
}

void Form::beSigned(Bureaucrat &b)
{
	if (this->isSigned)
		cout << GREEN << this->name << " is already signed :)" << RESET << std::endl;
	else
	{
		if (b.getGrade() > this->requiredGradeToSign)
			throw (Form::GradeTooLowException());
		this->isSigned = true;
		cout << WHITE << b.getName() << " sigend " << this->name << RESET << std::endl;
	}
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
