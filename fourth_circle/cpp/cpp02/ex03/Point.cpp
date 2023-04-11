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

#include "Point.hpp"

Point::Point(void): x(Fixed(0)), y(Fixed(0)) {}
Point::Point(Point const &p) : x(p.getX()), y(p.getY()){}
Point::Point(const float x, const float y) : x(x), y(y){}
Point::~Point(void){};
Point &Point::operator=(Point &p)
{
	if (this == &p)
		return *this;
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return this->x;
}

const Fixed &Point:: getY(void) const
{
	return this->y;
}

static float dotProduct(Point const a, Point const b, Point const c)
{
	float ret = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) 
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
			) / 2;
	if (ret < 0)
		return (ret * -1);
	return (ret);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float d0 = dotProduct(a,b,c);
	float d1 = dotProduct(a,b,point);
	float d2 = dotProduct(b,c,point);
	float d3 = dotProduct(a,c,point);
	if (d1 == 0 || d2 == 0 || d3 == 0 || d0 == 0)
		return (false);
	if (d1 + d2 + d3 == d0)
		return (true);
	return (false);

}
