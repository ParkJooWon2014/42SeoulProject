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

#ifndef ITER_HPP
#define ITER_HPP 

#include <iostream>

template<typename T>
void iter(T *adr, size_t len, void (*func)(T&))
{
	if (!adr | !func)
		return ;
	for (size_t i = 0 ; i < len ; i ++)
		func(adr[i]);
}

template<typename T>
void iter(T *adr, size_t len, void (*func)(T))
{
	if (!adr | !func)
		return ;
	for (size_t i = 0 ; i < len ; i ++)
		func(adr[i]);
}


#endif /* ifndef ITER_HPP */
