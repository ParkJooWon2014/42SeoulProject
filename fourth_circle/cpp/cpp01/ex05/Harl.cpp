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
	
#include "Harl.hpp"

Harl:: Harl(void)
{
	cout << "Harl!" << std::endl;
}

Harl::~Harl(void)
{
	cout << "Harl out!" << std::endl;
}

void Harl::debug(void)
{
	cout << RED <<"I love having extra bacon \
for my 7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
}

void Harl::info(void)
{
	cout << GRAY << "I cannot believe adding extra bacon costs more money. You didn’t put\
`enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	cout << MAGENTA<< "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	cout <<YELLOW << "This is unacceptable! I want to speak to the manager now."  << std::endl;
}

void Harl::complain(string level)
{
	const string menu[4] = {"DEBUG", "WARNING", "INFO", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::warning, &Harl::info, &Harl::error};

	for (int i = 0 ; i < 4 ; i++)
	{
		if (menu[i] == level){
			(this->*func[i])();
			return ;
		}
	}
	cout << "level is wrong" << std::endl;
}
