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

#ifndef VECTOR_HPP
#define VECTOR_HPP 

#include "iterator.hpp"

namespace ft{
	template<class T,class Allocator = std::allocator<T>> 
		class vector
	{
		public:

			typedef T value_type;
			typedef Allocator allocator_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename ft::random_access_iterator<value_type> iterator;
			typedef typename ft::random_access_iterator<const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

			private:
				allocator_type _alloc;
				pointer _start;
				pointer _end;
				pointer _end_capacity;


			public :
				explicit vector()
				{};
				vector() : _alloc(allocator_type()), _start(NULL), _end(NULL), _end_capacity(NULL)
				{}
				explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _alloc(allocator_type()), _start(NULL), _end(NULL), _end_capacity(NULL),
				{
					_start = _alloc.allocator(count);
					_end = _start;
					for (; count; count--)
						_alloc.construct(_end++, value);
				}

				template< class InputIt >
					vector(InputIt first, InputIt last,const Allocator& alloc = Allocator())
				{
					difference_type count = ft::distance(first, last);
					_start = _alloc.
				}
	};
};

#endif /* ifndef VECTOR_HPP */
