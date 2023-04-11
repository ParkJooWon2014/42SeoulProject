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


#include "WrongCat.hpp"


WrongCat::WrongCat(void)
{
	std::cout << "Wrong Cat constructor called" << std::endl;
	this->type ="WrongCat";
}

WrongCat::~WrongCat(void) 
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cat) 
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	this->type = cat.getType();
}

WrongCat &WrongCat::operator=(WrongCat const &cat)
{

	std::cout << "Wrong Cat copy operator called" << std::endl;
	this->type = cat.getType();
	return (*this);
}

void WrongCat::makeSound(void) const
{

	std::cout << "Ya.....야옹...  " << std::endl;
}
