/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:28:56 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 18:52:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << BOLD PURPLE "[" << this->_type << "]" RESET PURPLE " created"
			  << RESET << std::endl;
}

Ice::Ice(const Ice& toCopy) : AMateria(toCopy)
{
	this->_type = toCopy._type;
	std::cout << BOLD PP "[" << this->_type << "]" RESET PP " copy created"
			  << RESET << std::endl;
}

Ice&	Ice::operator=(const Ice& toCopy)
{
	if (this != &toCopy)
		AMateria::operator=(toCopy);
	return (*this);
}

Ice::~Ice()
{
	std::cout << BOLD ORANGE "[" << this->_type << "]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
