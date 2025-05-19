/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:15:13 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/19 15:27:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::cout << BOLD DARK_SAND "[MateriaSource]" RESET DARK_SAND " created"
			  << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& toCopy) : IMateriaSource(toCopy)
{
	std::cout << BOLD SAND "[MateriaSource]" RESET SAND " copy created"
			  << RESET << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << BOLD ORANGE "[MateriaSource]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	if (type != "ice" || type != "cure")
		return (0);
}
