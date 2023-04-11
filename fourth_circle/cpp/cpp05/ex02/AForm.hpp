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

#ifndef AFORM_HPP
#define AFORM_HPP 

#include <fstream>
#include "Bureaucrat.hpp"

typedef std::string string;

class Bureaucrat;

class AForm{

	public : 
		AForm(void);
		AForm(string const &name);
		AForm(string const &name, bool isSigned);
		AForm(int sign, int exec);
		AForm(AForm const &form);
		AForm(string const &name, int execGrade, int signGrade);
		virtual ~AForm(void);

	protected:
		const string name;
		bool isSigned;
		const int requiredGradeToSign;
		const int requiredGradeToExecute;
		string target;

	public :

		const string &getTarget(void) const;
		string getName(void) const;
		string isSignedS(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(Bureaucrat &b);

		virtual void execute(Bureaucrat const &b) const = 0;

		class AFormNotSignedException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &f);
typedef AForm Form;

#endif /*ifndef AFORM_HPP */
