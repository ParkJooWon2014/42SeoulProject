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

#ifndef DOG__HPP
#define DOG__HPP 

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog const &dog);
		~Dog(void);
		Dog &operator=(Dog const &dog);
	
	public :
		void makeSound(void) const;
};

#endif /* ifndef DOG__HPP */
