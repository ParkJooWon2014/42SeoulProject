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

#ifndef ITERATOR_HPP
#define ITERATOR_HPP 

#include <iostream>

// @brief iterator_traits는 LegacyIterator 유형의 속성에 대한 균일한 인터페이스를 제공하는 유형 특성 클래스입니다. 
// 이렇게 하면 반복자 측면에서만 알고리즘을 구현할 수 있습니다.
// 템플릿은 사용자 정의 반복자에 대해 특화될 수 있습니다.

namespace ft{

	template< class Iter > struct iterator_traits
	{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template< class T >struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template< class T >struct iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};
};

// @brief typedef ft::iterator_traits<It>::iterator_category는 
// 이러한 태그 유형 중 하나에 대한 별칭으로 정의되어 It이 속한 가장 구체적인 범주를 나타내야 합니다.
//https://en.cppreference.com/w/cpp/iterator/iterator_tags

namespace ft
{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
};

// Iterator 
namespace ft{

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator
		{
			typedef Category iterator_category;
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
		};

	template <class T>
		class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;

		private:
		pointer _elem;
	};

};

// Rerverse Iterator 

namespace ft
{
	template< class Iter>
		class reverse_iterator
		{
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;


			// 생성자 소멸자 
			reverse_iterator() : _elem()
			{};
			explicit reverse_iterator (iterator_type it): _elem(it)
			{};
			template <class Iter>
				reverse_iterator (const reverse_iterator<Iter>& rev_it):_elem(rev_it.base())
			{};
			virtual ~reverse_iterator() {};

			iterator_type base(void) const
			{return (_elem);}

			reference operator[](difference_type n) const
			{
				return (_elem[-n -1]);
			}

			reference operator*() const
			{
				iterator_type tmp = _elem;
				return *(--tmp);
			}
			pointer operator->() const
			{
				return &(operator*());
			}

			reverse_iterator& operator++()
			{
				--_elem;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			reverse_iterator& operator+= (difference_type n)
			{
				_elem -= n;
				return (*this);
			}
			reverse_iterator operator+ (difference_type n) const 
			{ 
				return (reverse_iterator(_elem - n)); 
			}

			reverse_iterator& operator--()
			{
				++_elem;
				return (*this);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}
			reverse_iterator& operator-= (difference_type n)
			{
				_elem += n;
				return (*this);
			}
			reverse_iterator operator- (difference_type n) const 
			{ 
				return (reverse_iterator(_elem + n)); 
			}
			private :
			iterator_type *_elem;
		};
	template <class Iterator>
		bool operator== (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator_L, class Iterator_R>
		bool operator== (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator_L, class Iterator_R>
		bool operator!= (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator>
		bool operator<  (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator_L, class Iterator_R>
		bool operator< (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator_L, class Iterator_R>
		bool operator<= (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator>
		bool operator> (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.bash()); }

	/* For reverser_iterator > const_reverse_iterator */
	template <class Iterator_L, class Iterator_R>
		bool operator> (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }

	template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

	/* For reverser_iterator >= const_reverse_iterator */
	template <class Iterator_L, class Iterator_R>
		bool operator>= (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iterator>
		reverse_iterator<Iterator> operator+ (
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- (
				const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

	template <class Iterator_L, class Iterator_R>
		bool operator- (const reverse_iterator<Iterator_L>& lhs,
				const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() - rhs.base()); }
};


/*
 * random iterator
 * 
 * */

namespace ft{
	template <typename T>
		class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef T*               pointer;
		typedef T&             reference;

		//constructor and destructor
		random_access_iterator(void): _elem(NULL){};
		random_access_iterator(pointer p) : _elem(p) {};
		random_access_iterator(const random_access_iterator& op):_elem(op.base()) {};

		virtual ~random_access_iterator() {}

		random_access_iterator &operator=(const random_access_iterator& op)
		{
			if (this == &op)
				return (*this);
			this->_elem = op.base();
			return (*this);
		}

		reference operator*(void) const 
		{ 
			return (*_elem); 
		}

		pointer operator->(void) 
		{ 
			return &(this->operator*()); 
		}

		random_access_iterator& operator++(void)
		{
			_elem++;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator rai(*this);
			rai++;
			return (rai);
		}

		random_access_iterator& operator--(void)
		{
			_elem--;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator rai(*this);
			rai--;
			return (rai);
		}
		random_access_iterator operator+(difference_type n) const 
		{ 
			return (_elem + n); 
		}
		
		random_access_iterator operator-(difference_type n) const 
		{ 
			return (_elem - n); 
		}

		random_access_iterator& operator+=(difference_type n)
		{
			_elem += n;
			return (*this);
		}

		random_access_iterator& operator-=(difference_type n)
		{
			_elem -= n;
			return (*this);
		}

		reference operator[](difference_type n) 
		{ 
			return (*(operator+(n))); 
		}
		
		operator random_access_iterator<const T> () const
		{ 
			return (random_access_iterator<const T>(this->_elem)); 
		}

		pointer base() const
		{ 
			return (this->_elem); 
		}

		private :
		pointer _elem;
	};
	
	 template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator==(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /* For iterator == const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator==(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /* For iterator != const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator!=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    /* For iterator < const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /* For iterator > const_iterator */
    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template<typename T_L,
             typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>=(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template<typename T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        typename ft::random_access_iterator<T>& rai)
        {
            return (&(*rai) + n);
        }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /* For iterator - const_iterator */
    template<typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator-(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }

};

#endif /* ifndef ITERATOR_HPP */
