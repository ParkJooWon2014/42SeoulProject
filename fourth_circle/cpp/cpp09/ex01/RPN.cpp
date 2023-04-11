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

#include "RPN.hpp"


RPN::RPN(void){}

RPN::~RPN(void){}

RPN &RPN::operator=(const RPN &r)
{
	this-> s = r.s;
	return (*this);
}

RPN::RPN(const RPN &r)
{
	(*this) = r;
}

int isDigit(std::string &line)
{
	if (line.length() == 1){
		if (isdigit(line[0]) || line == "-" || line == "+" || line == "*" || line == "/")
			return (0);
		else
			return (1);
	}
	size_t idx = line[0] == '-' || line[0] == '+' ? 1 : 0;

	for (; idx < line.length(); idx++)
	{
		if (!isdigit(line[idx]))
			return (1);
	}
	return (0);
}

static int cal(int first, int second, std::string &op, int &check)
{
	check  = 0;
	if (op == "-")
		return (first - second);
	else if(op == "+")
		return (first + second);
	else if (op == "*")
		return (first * second);
	else if (op == "/")
	{
		if (second == 0)
		{
			check = 1;
			return (-1);
		}
		return (first / second);
	}
	check = 1;
	return (-1);
}

int RPN::calInput(int &answer, std::string input)
{
	int first = 0;
	int second = 0;
	int check = 0;
	std::stringstream ss(input);
	std::string op;

	while (ss >> op)
	{
		if (isDigit(op) == 1)
			return (1);
		if (op == "+" || op == "-" || op == "*" || op == "/")
		{
			if (s.size() < 2)
				return  (1);
			second = s.top(); s.pop();
			first = s.top(); s.pop();
			s.push(cal(first, second, op, check));
			if (check)
				return (1);
		}
		else
			s.push(atoi(op.c_str()));
	}
	if (s.size() != 1)
		return (1);
	answer = s.top();
	return (0);
}
