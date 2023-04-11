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


#include "Cat.hpp"


Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type ="Cat";
	this->brain = new Brain();
}

Cat::~Cat(void) 
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &cat) :Animal() 
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(Cat const &cat)
{
	std::cout << "Cat copy operator called" << std::endl;
	this->type = cat.getType();
	this->brain = new Brain(*(cat.brain));
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Ya.....야옹...  " << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
