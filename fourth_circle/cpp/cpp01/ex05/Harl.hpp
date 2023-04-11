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

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

typedef std::string string;

#define cout std::cout

# define NORM "\033[1;40;37m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class Harl{

	public :
		Harl(void);
		~Harl(void);
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public :
		void complain(string level);
};

#endif
