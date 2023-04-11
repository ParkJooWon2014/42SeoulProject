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


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

typedef std::string string;

class Brain
{
	public :
		Brain(void);
		Brain(Brain const &brain);
		Brain &operator=(Brain const &brain);
		~Brain(void);

	protected :
		string ideas[100];
	
	public :
		const string (&getIdeas(void) const)[100];
		string getIdea(int n) const;
		int setIdea(int idx, string idea);
};


#endif /* ifndef BRAIN_HPP */
