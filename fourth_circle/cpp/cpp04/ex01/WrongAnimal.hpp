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

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP 

#include<iostream>

typedef std::string string;

class WrongAnimal{

	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &animal);
		WrongAnimal &operator=(WrongAnimal const &animal);
		~WrongAnimal(void);

	protected : 
		string type;
	public:
		void makeSound(void) const;
		string getType() const;

};


#endif /* ifndef ANIMAL_HPP */
