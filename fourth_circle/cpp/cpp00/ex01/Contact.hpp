/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <joowpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:24:20 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/27 18:14:16 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>

typedef std::string string;

#define cin std::cin
#define cout std::cout

enum type{
	FIRST,
	LAST,
	NICK,
	PHONENUM,
	SECRET,
	NR_INFO,
};

class Contact{
	private : 
		string info[NR_INFO];
	public :
		int	set_info(int type, string data);
		void print(void);
		void printFormat(int idx);
		string get_info(int type);
};

string idx_to_str(int idx);

#endif
