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

#include "ClapTrap.hpp"

static void     print_ending(void) {cout << "(...end test)" << std::endl;};

int main(void)
{
    {
        ClapTrap    wham("Wham!");
        
        wham.attack("Chuncky");
        wham.takeDamage(1);
        wham.beRepaired(3);
        wham.attack("another bot");
        wham.takeDamage(2);
        wham.beRepaired(4);
    }
    print_ending();
    
    {
        ClapTrap    c("some bot");
        ClapTrap    cc = c;
        
        c.attack("The Angel");
        c.takeDamage(4);
        c.beRepaired(2);
        cc.attack("The Entity");
        cc.takeDamage(3);
        cc.beRepaired(1);
    }
    print_ending();

    {
        ClapTrap    s("Seele");
        ClapTrap    ss(s);
        
        s.attack("Lilin");
        s.takeDamage(4);
        s.beRepaired(2);
        ss.attack("Adam");
        ss.takeDamage(3);
        ss.beRepaired(1);
    }
    print_ending();

    {
        ClapTrap().attack("them");
	}
    print_ending();
	return (0);
}
