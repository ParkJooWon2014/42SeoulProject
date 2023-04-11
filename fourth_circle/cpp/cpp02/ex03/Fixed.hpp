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

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

	public : 
		Fixed(void);
		Fixed(Fixed const &fix);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(Fixed const &fix);
		~Fixed(void);


		bool operator<(Fixed & fix) const;
		bool operator>(Fixed & fix) const;
		bool operator<=(Fixed & fix) const;
		bool operator>=(Fixed & fix) const;
		bool operator!=(Fixed & fix) const;
		bool operator==(Fixed & fix) const;

		Fixed operator+(Fixed const &a);
		Fixed operator-(Fixed const &a);
		Fixed operator*(Fixed const &a);
		Fixed operator/(Fixed const &a);

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);


		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private :
		static const int bit = 8;
		int value;

	public : 
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &, Fixed const &fix);

#endif
