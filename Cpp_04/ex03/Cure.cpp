/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:28:56 by panther           #+#    #+#             */
/*   Updated: 2025/05/19 16:30:29 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << BOLD BLUE "[" << this->_type << "]" RESET BLUE " created"
			  << RESET << std::endl;
}

Cure::Cure(const Cure& toCopy) : AMateria(toCopy)
{
	this->_type = toCopy._type;
	std::cout << BOLD PB "[" << this->_type << "]" RESET PB " copy created"
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
	std::cout << BOLD RED "[" << this->_type << "]" RESET RED " destroyed"
			  << RESET << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"
			  << std::endl;
}
