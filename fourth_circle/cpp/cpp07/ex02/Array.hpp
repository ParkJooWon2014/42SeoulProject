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

#ifndef ARRAY_HPP
#define ARRAY_HPP 

#include <iostream>

template <typename T>
class Array
{
	public :
		Array(void) : _size(0){array = new T[this->_size];}
		Array(unsigned int n) : _size(n) {
			array = new T[this->_size];
		}
		Array(Array const &a) : _size(a.size()) {
			this->array = NULL ;
			*this = a;
		};
		~Array(void){
			if (this->array) 
				delete [] array;
		};
		Array &operator=(Array const &a)
		{
			this->_size = a.size();
			if (this->array)
				delete[] this->array;
			this->array = new T[this->_size];
			for (size_t i = 0 ; i < a.size(); i ++)
				array[i] = a[i];
			return *(this);
		};

	private :
		size_t _size;
		T *array;
	
	public :
		class	InvalidIndexException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		size_t size(void) const
		{
			return (this->_size);
		}
		
		T &operator[](size_t idx)
		{
			if (this->_size <= idx || this->array == NULL)
				throw Array<T>::InvalidIndexException();
			return (this->array[idx]);
		}
		
		const T& operator[](size_t idx) const
		{
			if (this->_size <= idx || this->array == NULL)
				throw Array<T>::InvalidIndexException();
			return (this->array[idx]);
		}
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}

#endif /* ifndef ARRAY_HPP */
