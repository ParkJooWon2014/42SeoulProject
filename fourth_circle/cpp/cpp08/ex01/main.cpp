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

#define MAX_ITER 10000
#define OVER_ITER ( MAX_ITER * 5 )
int main()
{
	{
		Span a = Span(5);
		for (size_t i = 0; i < 6; i++)
		{
			try
			{
				a.addNumber(i);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl;
	}

	{
		srand(time(NULL));
		Span s = Span(MAX_ITER);
		for (int i = 0 ; i < OVER_ITER; i ++)
		{
			try{
				s.addNumber(rand() % OVER_ITER - OVER_ITER / 2);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				break;
			}
		}
		std::cout << "shortest span is " << s.shortestSpan() << std::endl;
		std::cout << "longest span is " << s.longestSpan() << std::endl;
	}

	{
		Span s = Span(2);
		try
		{
			s.addNumber(1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}
