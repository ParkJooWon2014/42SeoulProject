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
#include <string>
#include <fstream>

#define cout std::cout

typedef std::string string;


string replace(string &wstring, string org, string alt)
{
	string ret = "";
	size_t len = org.length();
	size_t pos = 0;
	size_t idx = 0;

	if (!len)
	{
		cout << "org nothing" << std::endl;
		return "";
	}
	while ((pos = wstring.find(org, idx)) != string::npos)
	{
		if (pos == idx)
		{
			ret += alt;
			idx += len;
		}
		else if (pos > idx)
		{
			ret += wstring[idx];
			idx += 1;
		}
	}
	ret += wstring.substr(idx);
	return (ret);
}

int main(int ac, char *av[])
{
	std::ofstream fout;
	std::ifstream fin;
	string whole_line;
	
	char ch;

	if (ac != 4)
	{
		cout << "Few Arg or Too much Arg" << std::endl;
		return (0);
	}
	
	fin.open(std::string(av[1]));
	if(!fin.is_open())
	{
		cout << "file name is wrong << " << std::endl;
		return (0);
	}
	fout.open(std::string(av[1])+ ".replace");
	if (!fout.is_open())
	{
		fin.close();
		cout << "out file is wrong " << std::endl;
		return (0);
	}
	while (!fin.eof() && fin >> std::noskipws >> ch)
		whole_line += ch;
	fout << replace(whole_line, string(av[2]), string(av[3]));
	fin.close();
	fout.close();
}
