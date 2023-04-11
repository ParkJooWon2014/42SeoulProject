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

#ifndef POINT_HPP
#define POINT_HPP value

#include "Fixed.hpp"

class Point{

	private :
		const Fixed x;
		const Fixed y;

	public :
		Point(void);
		Point(Point const &p);
		~Point(void);
		Point &operator=(Point &p);
		Point(const float x, const float y);
	public : 
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* ifndef POINT_HPP */
