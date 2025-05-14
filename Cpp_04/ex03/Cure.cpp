/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:28:56 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:56:04 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(std::string const& type) : AMateria(type)
{
	this->_type = "cure";
	std::cout << BOLD PGG "[" << this->_type << "]" RESET PGG " created"
			  << RESET << std::endl;
}

Cure::Cure(const Cure& toCopy) : AMateria(toCopy)
{
	this->_type = toCopy._type;
	std::cout << BOLD PG "[" << this->_type << "]" RESET PG " copy created"
			  << RESET << std::endl;
}

Cure&	Cure::operator=(const Cure& toCopy)
{
	if (this != &toCopy)
		AMateria::operator=(toCopy);
	return (*this);
}

Cure::~Cure()
{
	std::cout << BOLD PO "[" << this->_type << "]" RESET PO " destroyed"
			  << RESET << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *"
			  << std::endl;
}
