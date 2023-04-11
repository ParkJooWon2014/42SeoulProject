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


#include "Span.hpp"

Span::Span(void) : n(0) {};

Span::~Span(void){}

Span::Span(unsigned int n) : n(n){};

Span::Span(Span const &s): n(s.getSize()){
	*this = s ;
};

Span &Span::operator=(Span const &s)
{
	this->n = s.getSize();
	this->numbers = s.getNumbers();
	return (*this);
}

unsigned int Span::getSize(void) const
{
	return (this->n);
}

const std::vector<int> &Span::getNumbers(void) const
{
	return (this->numbers);
}

void Span::addNumber(int num)
{
	if (this->numbers.size() >= this->n)
		throw OverSizeException();
	this->numbers.push_back(num);
	sort(this->numbers.begin(), this->numbers.end());
}

int Span::shortestSpan(void)
{
	int ret = INT_MAX;

	if (this->numbers.size() < 2)
		throw LessSizeException();
	
	ret = this->numbers[1] - this->numbers[0];
	for (size_t i = 0; i < this->numbers.size() - 1; i++)
	{
		int tmp = numbers[i + 1] - numbers[i];
		if (ret > tmp)
			ret = tmp;
		if (!ret)
			break ;
	}
	return (ret);
}

int Span::longestSpan(void)
{
	if (this->numbers.size() < 2)
		throw LessSizeException();
	return (*(this->numbers.rbegin()) - *(this->numbers.begin()));
}

const char *Span::LessSizeException::what(void) const throw()
{
	return ("LIST SIZE UNDER 2");
}

const char *Span::OverSizeException::what(void) const throw()
{
	return ("LIST SIZE OVER N");
}

std::ostream &operator<<(std::ostream &os, Span const &s)
{
	std::vector<int> numbers = s.getNumbers();
	for (size_t i = 0 ; i < numbers.size() ; i ++)
		os << numbers[i] << " ";
	os << std::endl;
	return (os);
}
