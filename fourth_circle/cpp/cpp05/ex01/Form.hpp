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

#ifndef FORM_HPP
#define FORM_HPP 

#include "Bureaucrat.hpp"

typedef std::string string;

class Bureaucrat;

class Form{

	public : 
		Form(void);
		Form(string const &name);
		Form(string const &name, bool isSigned);
		Form(int sign, int exec);
		Form(string const &name, int execGrade, int signGrade);
		~Form(void);
	
	private :
		const string name;
		bool isSigned;
		const int requiredGradeToSign;
		const int requiredGradeToExecute;
	
	public :		
		string getName(void) const;
		string isSignedS(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(Bureaucrat &b);

	class GradeTooHighException : std::exception
	{
		public :
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : std::exception
	{
		public :
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &f);
#endif /* ifndef FORM_HPP */
