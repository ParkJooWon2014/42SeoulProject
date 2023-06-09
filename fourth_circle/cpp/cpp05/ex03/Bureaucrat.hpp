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

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


#define cout std::cout 

typedef std::string string;

class AForm;

class Bureaucrat
{
	private : 
		const string name;
		int grade;
	public : 
		Bureaucrat(string const &name);
		Bureaucrat(string const &name, int grade);
		Bureaucrat(void);

		string getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &form);

		void executeForm(AForm const &form) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);
#endif /* ifndef BUREAUCRAT_HPP */
