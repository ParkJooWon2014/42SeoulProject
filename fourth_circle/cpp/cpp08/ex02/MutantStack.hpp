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
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP 

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename MutantStack<T>::stack::container_type container;
		typedef typename container::iterator iterator;
		typedef typename container::reverse_iterator reverse_iterator;
		typedef typename container::const_iterator const_iterator;
		typedef typename container::const_reverse_iterator const_reverse_iterator;


		MutantStack(void) {};
		MutantStack(const MutantStack& obj) {*this = obj;};
		MutantStack& operator=(const MutantStack& obj) {*this = obj; return (*this);}
		~MutantStack(void) {};

		iterator begin(void) {return this->c.begin();}
		iterator end(void) {return this->c.end();}

		reverse_iterator rbegin(void) {return this->c.rbegin();}
		reverse_iterator rend(void) {return this->c.rend();}

		const_iterator cbegin(void) {return this->c.cbegin();}
		const_iterator cend(void) {return this->c.cend();}

		const_iterator crbegin(void) {return this->c.crbegin();}
		const_iterator crend(void) {return this->c.crend();}
};

#endif /* ifndef MUTANTSTACK_HPP */
