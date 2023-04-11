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


#ifndef DATA_HPP
#define DATA_HPP 

#include <iostream>

class Data 
{
	public :
		Data(void);
		~Data(void);
		Data &operator=(Data const &d);
		Data (Data const &d);
	
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
#endif /* ifndef DATA_HPP */
