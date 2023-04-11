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

#include "AForm.hpp"

AForm::AForm(void): name("No Name"), isSigned(false), requiredGradeToSign(10), requiredGradeToExecute(100), target("defualt"){}

AForm::AForm(string const &name): name(name), isSigned(false), requiredGradeToSign(10), requiredGradeToExecute(100), target("default"){}

AForm::AForm(string const &name, int signGrade, int execGrade): name(name), isSigned(false), requiredGradeToSign(signGrade), requiredGradeToExecute(execGrade) , target("default"){}

AForm::AForm(int sign, int exec): name("No Name"), isSigned(false), requiredGradeToSign(sign), requiredGradeToExecute(exec), target("default")
{
	if (sign > 150 || exec > 150)
		throw(AForm::GradeTooLowException());
	if (sign < 1 || exec < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm(void){}

AForm::AForm(AForm const &form): name(form.getName()), isSigned(form.getSigned()), 
	requiredGradeToSign(form.getSignGrade()), requiredGradeToExecute(form.getExecGrade()) {}

string AForm::getName(void) const
{
	return this->name;
}

string AForm::isSignedS(void) const
{
	if (this->isSigned)
		return "SIGNED!";
	else
		return "NO SIGNED";
}

bool AForm::getSigned(void) const
{
	return this->isSigned;
}

int AForm::getSignGrade(void) const
{
	return this->requiredGradeToSign;
}

int AForm::getExecGrade(void) const
{
	return this->requiredGradeToExecute;
}

std::ostream &operator<<(std::ostream &s, AForm const &f)
{
	s << "FORM : "<< f.getName() << " " << f.isSignedS() << " and required grad : " << f.getSignGrade() <<
		" and exec grade " << f.getExecGrade();
	return s;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (this->isSigned)
		cout << GREEN << this->name << " is already signed :)" << RESET << std::endl;
	else
	{
		if (b.getGrade() > this->requiredGradeToSign)
			throw AForm::GradeTooLowException();
		this->isSigned = true;
		cout << WHITE << b.getName() << " sigend " << this->name << RESET << std::endl;
	}
}

const char *AForm::AFormNotSignedException::what(void) const throw()
{
	return ("Grade not signed");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const string &AForm::getTarget(void) const
{
	return (this->target);
}
