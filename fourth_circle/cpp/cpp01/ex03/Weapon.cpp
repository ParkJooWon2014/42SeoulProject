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

#include "Weapon.hpp"

Weapon::Weapon(void){}
Weapon::~Weapon(void){}

Weapon:: Weapon(string type)
	: type(type)
{}

int Weapon::setType(string type)
{
	if (type != "")
		this->type = type;
	else
		this->type = "LOVING YOU";
	return (0);
}

const string &Weapon::getType(void) {return (this->type);}
