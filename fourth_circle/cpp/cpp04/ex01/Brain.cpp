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

#include "Brain.hpp" 

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &brain)
{
	*this = brain;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &brain)
{
	for (int i = 0 ; i < 100; i ++)
		this->ideas[i] = brain.getIdea(i);
	return (*this);
}

string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx > 99)
		return "";
	return this->ideas[idx];
}

const string (&Brain::getIdeas(void) const)[100]
{
	return (this->ideas);
}

int Brain::setIdea(int idx, string idea)
{
	if (idx < 0 || idx > 99)
		return (1);
	this->ideas[idx] = idea;
	return (0);
}
