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

#include "Data.hpp"

Data::Data(void){}

Data::Data(Data const &d){ (*this) = d; }

Data::~Data(void){}

Data &Data::operator=(Data const &d)
{
	(void)d;
	return (*this);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *> (raw));
}
