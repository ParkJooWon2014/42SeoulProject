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

#ifndef UTILS_HPP
#define UTILS_HPP 

namespace ft{
	//ft_is_integral

	typename <bool is_integral, typename T>
		struct integral_constant
		{
			typedef T type_name;
			bool value;

			operator bool() const{ return value};
		};

	template<typename> struct is_integral_type : public integral_constant<false, bool> {};
	template<> struct is_integral_type : public integreal_constant<true, bool> {};
	template<> struct is_integral_type : public integreal_constant<true, char> {};
	template<> struct is_integral_type : public integreal_constant<true, char16_t> {};
	template<> struct is_integral_type : public integreal_constant<true, char32_t> {};
	template<> struct is_integral_type : public integreal_constant<true, wchar_t> {};
	template<> struct is_integral_type : public integreal_constant<true, short> {};
	template<> struct is_integral_type : public integreal_constant<true, int> {};
	template<> struct is_integral_type : public integreal_constant<true, long> {};
	template<> struct is_integral_type : public integreal_constant<true, long long> {};
	template<> struct is_integral_type<long long int> : public integreal_constant<true, long long int> {};
	template<> struct is_integral_type<unsigned char> : public integreal_constant<true, unsigned char> {};
	template<> struct is_integral_type<unsigned short int> : public integreal_constant<true, unsigned short int> {};
	template<> struct is_integral_type<unsigned int> : public integreal_constant<true, unsigned int> {};
	template<> struct is_integral_type<unsigned long int> : public integreal_constant<true, unsigned long int> {};
	template <> struct is_integral_type<unsigned long long int> : public integreal_constant<true, unsigned long long int> {};

	template <typename T>
		struct is_integral : public is_integral_type<T> {};


	// ft_enable_if 
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
			while (first != last)
			{
				first++;
				rtn++;
			}
			return (rtn);
		};

};

#endif /* ifndef UTILS_HPP */
