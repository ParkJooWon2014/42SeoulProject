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
#include <string>

#define string std::string
#define cout std::cout

int main(void)
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "Pointer of CMP " << std::endl;
	cout << "original: "<< &str << std::endl;
	cout << "Pointer: "<< stringPTR << std::endl;
	cout << "Refernce: " << &stringREF << std::endl;

	cout << "\n value of variable" << std::endl;
	cout << "original: "<< str << std::endl;
	cout << "Pointer: "<< *stringPTR << std::endl;
	cout << "Refernce: " << stringREF << std::endl;
	return (0);
}

