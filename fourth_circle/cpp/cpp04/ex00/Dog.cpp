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


#include "Dog.hpp"


Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type ="Dog";
}

Dog::~Dog(void) 
{
	std::cout << "Dog destructor called" << std::endl;
}
Dog::Dog(Dog const &dog) :Animal() 
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = dog.getType();
}

Dog &Dog::operator=(Dog const &dog)
{
	std::cout << "Dog copy operator called" << std::endl;
	this->type = dog.getType();
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Brr.....왈 왈 " << std::endl;
}
