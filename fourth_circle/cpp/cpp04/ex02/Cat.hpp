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
#ifndef CAT_HPP
#define CAT_HPP 

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	
	public :
		Cat(void);
		Cat(Cat const &dog);
		~Cat(void);
		Cat &operator=(Cat const &cat);
	
	public :
		void makeSound(void) const;
		Brain *getBrain(void) const;

};

#endif /* ifndef CAT_HPP */
