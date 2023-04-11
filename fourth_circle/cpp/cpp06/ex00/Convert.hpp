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

#ifndef COMVERT_HPP
#define COMVERT_HPP 

#include <iostream>
#include <stdlib.h>
#include <float.h>
typedef std::string string;

enum type
{
	CH,
	INT,
	FLOAT,
	DOUBLE,
	NAN_INF,
	NR_CAST,
	ERROR,
	NOTHING,
};

class Convert
{

	public : 
		Convert(void);
		Convert(Convert const &c);
		~Convert(void);
		Convert &operator=(Convert const &c);

	private :
		int type;
		double dValue;
		float fValue;
		int iValue;
		char cValue;
		string input;
		int getType(void) const;
	public :
		string getInput(void) const;
		char getCh(void) const;
		double getDouble(void) const;
		float getFloat(void) const;
		int getInt(void) const;
		void setValue(string input);
		void printValue(void) const;
};

#endif /* ifndef COMVERT_HPP */
