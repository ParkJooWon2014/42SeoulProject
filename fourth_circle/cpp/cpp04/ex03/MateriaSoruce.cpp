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

#include "MateriaSoruce.h"

MateriaSoruce::MateriaSoruce(void)
{
	slot[ICE] = NULL;
	slot[CURE] = NULL;
}

MateriaSoruce::MateriaSoruce(MateriaSoruce const &m)
{
	*this = m;
}

MateriaSoruce::~MateriaSoruce(void)
{
	for (int i = 0 ; i < 2; i ++)
	{
		if (this->slot[i])
			delete this->slot[i];
	}
}

MateriaSoruce &MateriaSource::operator=(MateriaSource const &m)
{
	for (int i = 0 ; i < 2; i++)
	{
		if (m.slot[i])
			this->slot[i] = new MateriaSource(*(m.slot[i]));
	}
	return *this;
}

MateriaSource
