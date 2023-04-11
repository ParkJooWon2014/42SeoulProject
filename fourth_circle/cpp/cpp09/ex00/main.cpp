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

#include "BitcoinExchange.hpp"

int main(int ac, char **argv)
{
	std::ifstream is;
	std::string line;
	std::map<std::string, double> db;

	if (ac != 2)
	{
		std::cout << "Invalid file name" << std::endl;
		return (0);
	}
	is.open(argv[1]);
	if (is.fail())
	{
		std::cout << "Cannot open file => " << argv[1] << std::endl;
		return (1);
	}
	if (getDataBase(db))
	{
		std::cout <<"Database is wrong" << std::endl;
		return (1);
	}
	if (getline( is, line))
		isValidLine(db, line, 1);
	while (getline(is, line))
		isValidLine(db, line, 0);
	return (0);
}
