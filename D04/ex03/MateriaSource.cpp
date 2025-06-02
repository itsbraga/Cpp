/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:15:13 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 18:18:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
MateriaSource::MateriaSource() : IMateriaSource(), _count(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << BOLD DARK_SAND "[MateriaSource]" RESET DARK_SAND " created"
			  << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& toCopy) : IMateriaSource(toCopy),
															_count(toCopy._count)
{
	for (int i = 0; i < 4; i++)
	{
		if (toCopy._inventory[i] != NULL)
			this->_inventory[i] = toCopy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << BOLD SAND "[MateriaSource]" RESET SAND " copy created"
			  << RESET << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& toCopy)
{
	if (this != &toCopy)
	{
		this->_count = toCopy._count;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (toCopy._inventory[i] != NULL)
				this->_inventory[i] = toCopy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << BOLD ORANGE "[MateriaSource]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL || this->_count == 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			this->_count++;
			return ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (0);
}
