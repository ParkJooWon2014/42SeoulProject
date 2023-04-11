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

#ifndef PMERGE_HPP
#define PMERGE_HPP 

#include <iostream>
#include <deque>
#include <vector>
#include <time.h>
#include <ctime>
#include <sys/time.h>

void PmergeMeDeque(std::deque<int> &numbers, int rate);
void PmergeMeVector(std::vector<int> &numbers, int rate);
#endif /* ifndef PMERGE_HPP */
