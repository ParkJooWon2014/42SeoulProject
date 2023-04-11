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
#include "Cat.hpp"
#include <stdlib.h>


int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    Dog basic;
    {
        Dog tmp = basic;
    }

    delete j;//should not create a leak
    delete i;

	Dog *d = new Dog();
	d->getBrain()->setIdea(0, "Hungry");
	Dog *copyD = new Dog(*d);
	d->getBrain()->setIdea(0, "Full");

	std::cout <<"Orginanl : " << d->getBrain()->getIdea(0) << std::endl;
	std::cout <<"Copy : " << copyD->getBrain()->getIdea(0) << std::endl;

	delete d;
	delete copyD;
	
	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }
	
	return 0;
}
