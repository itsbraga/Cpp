/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:28:56 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 18:52:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
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
