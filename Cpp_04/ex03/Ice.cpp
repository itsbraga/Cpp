/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:28:56 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:20:43 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Ice.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Ice::Ice() : AMateria("ice")
{
	std::cout << BOLD BLUE "[" << this->_type << "]" RESET BLUE " created"
			  << RESET << std::endl;
}

Ice::Ice(const Ice& toCopy) : AMateria(toCopy)
{
	this->_type = toCopy._type;
	std::cout << BOLD PB "[" << this->_type << "]" RESET PB " copy created"
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
	std::cout << BOLD RED "[" << this->_type << "]" RESET RED " destroyed"
			  << RESET << std::endl;
}

/*
	------------------------- [ Main functions ] -------------------------
*/
AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
