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

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

	try
	{
		Bureaucrat human("oliver",20);
		ShrubberyCreationForm myTree("mjung");
		RobotomyRequestForm robotomy("tommy");
		PresidentialPardonForm pardon("nice dog");

		// 사람 등급 출력
		cout << human << std::endl;

		 // 각각의 폼에 대한 정보 출력
		cout << robotomy << std::endl;
		cout << myTree << std::endl;
		cout << pardon << std::endl;

		// 각각의 폼에 싸인 시도
		myTree.beSigned(human);
		robotomy.beSigned(human);
		pardon.beSigned(human);

		// 각각의 폼에 싸인이 되었는지 확인
		human.signForm(myTree);
		human.signForm(robotomy);
		human.signForm(pardon);

		// 싸인이 되어있고, 실행등급이 충분하다면 실행
		// 권한 부족시 예외 처리
		myTree.execute(human);
		robotomy.execute(human);
		human.executeForm(pardon);
		pardon.execute(human);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
