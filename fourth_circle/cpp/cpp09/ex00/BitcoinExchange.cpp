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

inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
	s.erase(0, s.find_first_not_of(t));
	return s;
}

inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}

inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
	return ltrim(rtrim(s, t), t);
}

inline std::string getItem(std::list<std::string> node, int idx)
{
	return *(next(node.begin(), idx));
}

static std::list<std::string> split(std::string &input, char delimiter) {
	std::list<std::string> answer;
	std::stringstream ss(input.c_str());
	std::string temp;

    while (getline(ss, temp, delimiter)){
		//temp = trim(temp);
		if (temp.length() != 0)
			answer.push_back(trim(temp));
    }
    return answer;
}

static int isInt(std::string sNum)
{
	for (size_t i = 0; i < sNum.length(); i ++)
	{
		if (!isdigit(sNum[i]))
			return (1);
	}
	return (0);
}

static int isValidDate(int year, int month, int day)
{
	if (year < 0 || month < 0 || month > 12 || day < 0 || day >31)
		return (1);
	if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11){
		if (day > 30)
			return (1);
		if (month == 2){
			if ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0)){
				if (day > 29)
					return (1);
				return (0);
			}
			else{
				if (day > 28)
					return (1);
				return (0);
			}
		}
	}
	return (0);
}

static int isValidMonth(std::string sDate)
{
	std::list<std::string> tokens = split(sDate, '-');
	int year = 0;
	int month = 0;
	int day = 0;
	if (tokens.size() != 3)
	{
		std::cout << "Error : bad input to data => " << sDate << std::endl;
		return (1);
	}
	for (size_t idx = 0; idx < 3; idx++)
	{
		if (isInt(getItem(tokens,idx)))
		{
			std::cout << "Error : bad input do to Data => " << sDate << std::endl;
			return (1);
		}
	}
	year = atoi(getItem(tokens, 0).c_str()), month = atoi(getItem(tokens, 1).c_str()), day = atoi(getItem(tokens, 2).c_str());
	if (isValidDate(year, month, day))
	{
		std::cout << "Error : bad input do to Data => " << sDate << std::endl;
		return (1);
	}
	return (0);
}

static int isValidRate(std::string sFloat, int isDb)
{
	size_t idx = 0;
	float num = 0.0;

	for (; idx < sFloat.length(); idx++){
		if (sFloat[idx] == '.'){
			idx += 1;
			break ;
		}
		else if (!isdigit(sFloat[idx]))
		{
			std::cout << "Error : bad input for value => " << sFloat << std::endl;
			return (1);
		}
	}
	for (; idx < sFloat.length(); idx++)
	{
		if (!isdigit(sFloat[idx]))
		{
			std::cout << "Error : bad input for data => " << sFloat << std::endl;
			return (1);
		}
	}
	num = atof(sFloat.c_str());
	if (!isDb && num < 0)
	{
		std::cout << "Error : Negative number" << std::endl;
		return (1);
	}
	else if (!isDb && num > 1000)
	{
		std::cout << "Error : too large a number" << std::endl;
		return (1);
	}
	return (0);
}

int isValidLine(std::map<std::string, double> &db, std::string &line, int isFirstline)
{
	std::list<std::string>tokens;
	std::stringstream ss(line.c_str());
	float ret = 0.0;
	int cnt = 0;

	std::map<std::string, double>::iterator lower, upper, iter;

	for (size_t i = 0;i < line.length(); i ++){
		if (line[i] == '|')
			cnt += 1;
		if (cnt > 1){
			std::cout << "Error: bad input => " << line << std::endl;
			return (0);
		}
	}
	tokens = split(line, '|');
	if (tokens.size() != 2)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	if (isFirstline)
	{
		std::cout << line << std::endl; 
		return (0);
	}
	if (isValidMonth(getItem(tokens, 0)))
		return (0);
	if (isValidRate(getItem(tokens, 1), 0))
		return (0);
	lower = db.lower_bound(getItem(tokens, 0));
	upper = db.upper_bound(getItem(tokens, 0));
	if (lower == db.end())
		iter = prev(db.end());
	else if (lower == db.begin() && upper == db.begin())
	{
		std::cout << "There is no DB in Data" << std::endl;
		return (0);
	}
	else
		iter = lower;
	ret = (double)(iter->second) * (double)atof(getItem(tokens, 1).c_str());
	std::cout << getItem(tokens, 0) << " => " << getItem(tokens, 1) << " = " << ret << std::endl;
	return (0);
}

int getDataBase(std::map<std::string, double> &db, std::string data)
{
	std::ifstream is(data.c_str());
	std::string line;
	
	if (is.fail())
		return (1);
	if (!getline(is ,line))
		return (1);
	if (split(line, ',').size() != 2)
		return (1);
	while (getline(is, line))
	{
		trim(line);
		if (line.length() == 0)
			continue;
		std::list<std::string> tokens = split(line, ',');
		if (tokens.size() != 2)
			return (1);
		if (isValidMonth(getItem(tokens, 0)))
			return (1);
		if (isValidRate(getItem(tokens, 1), 1))
			return (1);
		db[getItem(tokens, 0)] = atof(getItem(tokens, 1).c_str()); 
	}
	return (0);
}
