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

#include "Fixed.hpp"

Fixed:: Fixed(void) : value(0) { std::cout << "Default constructor called" << std::endl;};
Fixed:: Fixed(Fixed const &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
	//this->value = fix.getRawBits();
}
Fixed:: Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bit;
}

Fixed:: Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(((value) * (1 << this->bit)));
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->bit);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bit));
}

std::ostream &operator<<(std::ostream &s, Fixed const &fix)
{
	s << fix.toFloat();
	return (s);
};

Fixed:: ~Fixed(void) {std::cout << "Destructor called" << std::endl;}

Fixed	&Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
