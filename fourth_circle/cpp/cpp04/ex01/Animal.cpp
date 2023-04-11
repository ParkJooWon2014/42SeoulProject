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

#include "Animal.hpp"

Animal::Animal(void) : type("No type") 
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(Animal const &ani) : type(ani.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal(void) 
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &ani)
{
	std::cout << "Animal copy operator called" << std::endl;
	this->type = ani.getType();
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "No type animal make sound" << std::endl;
}

string Animal::getType(void) const
{
	return this->type;
}
