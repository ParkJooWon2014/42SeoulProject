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
	this->brain = new Brain();
}

Dog::~Dog(void) 
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(Dog const &dog) :Animal() 
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(Dog const &dog)
{
	std::cout << "Dog copy operator called" << std::endl;
	this->type = dog.getType();
	this->brain = new Brain(*(dog.brain));
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Brr.....왈 왈 " << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
