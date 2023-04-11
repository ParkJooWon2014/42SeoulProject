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

#ifndef SPAN_HPP
#define SPAN_HPP 

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{

	public :
		Span(void);
		~Span(void);
		Span(unsigned int n);
		Span(Span const &s);
		Span &operator=(Span const &s);

	private :
		unsigned int n;
		std::vector<int> numbers;

	public :
	
		unsigned int getSize(void) const;
		const std::vector<int> &getNumbers(void) const;
		void addNumber(int number);
		int shortestSpan(void);
		int longestSpan(void);

	class LessSizeException: public std::exception
	{
		public:
			const char * what(void) const throw();
	};

	class OverSizeException: public std::exception
	{
		public:
			const char * what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Span const &s);
#endif /* ifndef SPAN_HPP */
