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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm ("ShrubberyCreationForm",145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(string name)
	:AForm("ShrubberyCreationForm", 145, 137)
{
	target = name;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f)
	:AForm("ShrubberyCreationForm", 145, 137) 
{
	target = f.getTarget();
	*this = f;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &f)
{
	this->target = f.getTarget();
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	if ((int)b.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::AFormNotSignedException());
	else
	{
		std::ofstream os ((this->getTarget() + "_shrubbery").c_str());
	os << " \
                       O			\n\
                      ***            \n\
                     **O**            \n\
                    *******            \n\
                   *********            \n\
                  ***********           \n\
                   ******o**            \n\
                  ***********                   \n \
                 ****o********                   \n\
                ***************                  \n\
               ****o***o********                 \n\
              *******************                \n\
            ***********************              \n\
               *****O***********                 \n\
              **********o********                \n\
             ****************o****               \n\
            **O********************              \n\
           ***********o********O****             \n\
         *****************************           \n\
             *********************               \n\
            ***o*******************              \n\
           ***********o*******o*****             \n\
          ***************************            \n\
         ***********************O*****           \n\
        ***O***************************          \n\
      ***********************************        \n\
                      ###                        \n\
                      ###                        \n\
                      ###                        \n\
                  ###########                    \n\
                  ###########       " << std::endl;
	  cout << GREEN<< b.getName() << "Signed ShrubberyCreationForm to "  << target << RESET <<std::endl;
	}
}
