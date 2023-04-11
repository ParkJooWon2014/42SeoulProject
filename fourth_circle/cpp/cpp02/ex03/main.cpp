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

#include <iostream>
#include "Point.hpp"
static void	print_3pts(Point const, Point const, Point const, Point const);
# define called " called\n"
# define inside "\ninside "
# define nl2 " \n\n"
# define nl " \n"
// colors
# define CYAN	"\x1b[36m"
// # define YELL	"\x1b[33;40m"
# define YELL	"\033[0;33m"
# define REST	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define PASS	GREEN "passed" REST
# define FAIL	RED "failed" REST


int main()
{
	bool	flag;

	// Test 1
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		. b {10,30}
		//             / \
		//            /   \
		//           /     \
		//          /   . P {10, 15}
		//         /         \
		//  a {0,0} ---------- c {20,0} 

		Point const	P(10, 15);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);

		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(flag);
	}
	// Test 2
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		.	b, P {10,30} (same coor)
		//             / \
		//            /   \
		//           /     \
		//          /       \
		//         /         \
		//  a {0,0} ---------- c {20,0}

		Point const	P(10, 30);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);

		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(! flag);
	}
	// Test 3
	{
		Point const	p1(0, 0);
		Point const	p2(10, 30);
		Point const	p3(20, 0);

		//		b
		//		.		. P
		//             / \
		//            /   \
		//           /     \
		//          /       \
		//         /         \
		//  a {0,0} ---------- c {20,0} 


		Point const	P(1000, 3000);
		
		print_3pts(p1, p2, p3, P);
		flag = bsp(p1, p2, p3, P);
		
		if (flag)
		{
			std::cout << "Result  \t" GREEN "Yes it is." REST;
		}
		else
		{
			std::cout << "Result  \t" RED "No it is not." REST;
		}
		std::cout << nl2;

		assert(! flag);
	}
	// test 4
	{
		Point const	p1(-4, 0);
		Point const	p2(12, 8);
		Point const	p3(12, 0);

		//
		//                                     . P
		//
		//                        (8, 6) .     |
		// 
		//                       .             |
		//
		//                . (2, 3)             |
		//
		//         .                           |
		//  a {-4,0} -------------------- c {12,0} 

		// somewhere on the slope
		{
			Point const	P(2, 3);
		
			print_3pts(p1, p2, p3, P);
			flag = bsp(p1, p2, p3, P);

			if (flag)
			{
				std::cout << "Result  \t" GREEN "Yes it is." REST;
			}
			else
			{
				std::cout << "Result  \t" RED "No it is not." REST;
			}
			std::cout << nl2;
			assert(! flag);
		}	
	}
}


// helper


static void print_3pts(Point const p1, Point const p2, Point const p3, Point const P)
{
	std::cout << CYAN "Point 1 \ta " << REST "{"
	<< p1.getX().toFloat() << ", " << p1.getY().toFloat() << "} \n";
	std::cout << CYAN "Point 2 \tb " << REST "{" 
	<< p2.getX().toFloat() << ", " << p2.getY().toFloat() << "} \n";
	std::cout << CYAN "Point 3 \tc " << REST "{" 
	<< p3.getX().toFloat() << ", " << p3.getY().toFloat() << "} \n";

	std::cout << YELL "Inspect \tP " << REST "{" 
	<< P.getX().toFloat() << ", " << P.getY().toFloat() << "} \n";
}
