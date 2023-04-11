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
{}

Harl::~Harl(void)
{}

void Harl::debug(void)
{
	cout <<RED << "[ DEBUG ]\n";
	cout << RED <<"I love having extra bacon \
for my 7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!\n" << std::endl;
}

void Harl::info(void)
{
	cout << GRAY << "[ INFO ]\n";
	cout << GRAY << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	cout << MAGENTA << "[ WARNING ]\n";
	cout << MAGENTA << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	cout << YELLOW << "[ ERROR ]\n";
	cout <<YELLOW << "This is unacceptable! I want to speak to the manager now.\n"  << std::endl;
}

static uint64_t myHash(string line)
{
	uint64_t ret = 0;

	for (size_t i = 0 ; i < line.length(); i ++)
		ret = ret * 256 + (char)line[i];
	return (ret);
}

void Harl::complain(string level)
{
	(void)level;
	int idx = 0;
	const string menu[4] = {"DEBUG","INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (myHash(level))
	{
		case 293219751239:
			(this->*func[0])();
		case 1229866575:
			(this->*func[1])();
		case 24560144730377799: 
			(this->*func[2])();
		case 297733869394:
			(this->*func[3])();
			idx = 1;
			break;
	}
	if (!idx)
		cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
