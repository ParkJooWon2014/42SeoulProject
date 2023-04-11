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
#include "Form.hpp"

int main(void)
{

	{
		cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		cout << std::endl;

		cout << "\033[34mTesting\033[0m" << std::endl;
		cout << *a << std::endl;
		cout << *b << std::endl;
		
		try
		{
			b->beSigned(*a);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}
		
		cout << *b;
		cout << std::endl;

		cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		cout << std::endl;
	}
	
	cout << "-------------------------------------------------------" << std::endl;
	{
		cout << std::endl;

		cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		cout << std::endl;

		cout << "\033[34mTesting\033[0m" << std::endl;
		cout << *a << std::endl;
		cout << *b << std::endl;
		cout << *c << std::endl;

		// Assistant signs the Form
		try
		{
			// c->beSigned(*a);
			a->signForm(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		cout << *c << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		cout << *c << std::endl;

		// try signing the from again
		b->signForm(*c);
		cout << std::endl;

		cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		cout << std::endl;
	}
	cout << "-------------------------------------------------------" << std::endl;
	{
		cout << std::endl;

		cout << "\033[34mConstructing\033[0m" << std::endl;
		Form *a = NULL;

		// sign-grade too high
		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
				e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
				e.what() << "\033[0m" << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
				e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
				e.what() << "\033[0m" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			cout << std::endl;
			cout << "\033[34mDeconstructing\033[0m" << std::endl;
			delete a;
		}
		cout << std::endl;
	}
	return (0);
}

