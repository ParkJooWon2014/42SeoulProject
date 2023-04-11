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

#include "Convert.hpp"

Convert::Convert(void)
{
	this->input = "nothing";
	this->dValue = 0.0;
	this->fValue = 0.0f;
	this->iValue = 0;
	this->cValue = 0;
}

Convert::Convert(Convert const &c)
{
	*this = c;
}

Convert::~Convert(void)
{}

Convert &Convert::operator=(Convert const &c)
{
	if (this == &c)
		return *this;
	input = c.getInput();
	dValue = c.getDouble();
	cValue = c.getCh();
	fValue = c.getFloat();
	iValue = c.getInt();
	return (*this);
}

static int isComposeOf(string &org, string cmp)
{
	int dict[256] = {0, };

	for (size_t i = 0 ; i < cmp.length(); i ++)
		dict[(unsigned int) cmp[i]] = 1;
	for (size_t i = 0 ; i < org.length(); i ++)
	{
		if (!dict[(unsigned int)org[i]])
			return (0);
	}
	return (1);
}

static int isInt(string number)
{
	if (number[0] == '-' || number[0] == '+')
		number = number.substr(1, number.length() - 1);
	if (isComposeOf(number,"0123456789"))
		return (1);
	return (0);
}

static int isDouble(string number)
{
	size_t i = 0;
	size_t len = 0;

	if (number[0] == '-' || number[0] == '+')
		number = number.substr(1, number.length() - 1);
	len = number.length();
	for (i = 0 ; i < len; i ++)
	{
		if (number[i] == '.')
			break ;
		if (!isdigit(number[i]))
			return (0);
	}
	if (i == len || (i + 1) == len)
		return (0);
	i++;
	for (; i < len ; i++)
	{
		if (!isdigit(number[i]))
			return (0);
	}
	return (1);
}

static int isFloat(string input)
{
	if (input[input.length() - 1] == 'f' && isDouble(input.substr(0, input.length() - 1)))
		return (1);
	return (0);
}

int Convert::getType(void) const
{
	if (input.length() == 0)
		return (NOTHING);
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "nanf" ||
			input == "+inff" || input == "-inff")
		return (NAN_INF);
	if (input.length() == 1 && !isdigit(input[0]))
		return (CH);
	else if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	return (ERROR);
}

void Convert::setValue(string input)
{
	this->input = input;

	this->type = this->getType();
	if (this->type == NOTHING)
		return ;
	this->dValue = atof(this->input.c_str());
	this->iValue = static_cast<int>(dValue);
	this->fValue = static_cast<float>(dValue);
	if (this->type == CH)
	{
		this->cValue = this->input[0];
		this->dValue = static_cast<double>(cValue); 
		this->iValue = static_cast<int>(dValue);
		this->fValue = static_cast<float>(dValue);
	}
	else
		this->cValue = static_cast<char>(dValue); 
	return ;
}

void Convert::printValue(void) const
{
	string number ;

	if (this->type == NOTHING)
	{
		std::cout << "DONT TEST ME! I know you will input nothing !" << std::endl;
		return ;
	}
	// char print
	std::cout << "char: ";
	if (this->type == NAN_INF || this->type == ERROR || dValue < SCHAR_MIN || dValue > SCHAR_MAX)
		std::cout << "impossible" <<  std::endl;
	else
	{
		if (!isprint(cValue))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << cValue << "'" <<std::endl;
	}

	//int print
	std::cout << "int: ";
	if (this->type == NAN_INF || this->type == ERROR || dValue > INT_MAX || dValue < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << iValue << std::endl;

	number = input;
	if (number[number.length() - 1] == 'f')
		number = number.substr(0, number.length() - 1);
	if (number.find(".") == std::string::npos)
		number = number + ".0";

	// float Print
	std::cout << "float: ";
	if (this->type == NAN_INF)
	{
		if (this->input == "nan" || this->input == "nanf")
			std::cout << "nanf" << std::endl;
		else if (this->input == "+inff" || this->input == "+inf") 
			std::cout << "+inff" << std::endl;
		else 
			std::cout << "-inff" << std::endl;
	}
	else if (this->type == ERROR || dValue > (double)FLT_MAX || dValue < -FLT_MAX )
		std::cout << "impossible" << std::endl;
	else if (this->type == CH)
		std::cout << fValue << ".0f" << std::endl;
	else
		std::cout << number << "f" << std::endl;

	// doouble Print
	std::cout << "double: ";
	if (this->type == ERROR)
		std::cout << "impossible" << std::endl;
	else if (this->type == NAN_INF)
	{
		if (this->input == "nan" || this->input == "nanf")
			std::cout << "nan" << std::endl;
		else if (this->input == "+inff" || this->input == "+inf") 
			std::cout << "+inf" << std::endl;
		else 
			std::cout << "-inf" << std::endl;
	}
	else if (this->type == CH)
		std::cout << dValue << ".0" << std::endl;
	else
		std::cout << number << std::endl;
}

string Convert::getInput(void) const
{
	return input;
}
char Convert::getCh(void) const
{
	return cValue;
}

double Convert::getDouble(void) const
{
	return dValue;
}

float Convert::getFloat(void) const
{
	return fValue;
}

int Convert::getInt(void) const
{
	return iValue;
}
