/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:17:49 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 21:45:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << BOLD BLUE "[AMateria " UNDERLINE << this->_type << RESET "]"
			  << BLUE " created" RESET << std::endl;
}

AMateria::AMateria(const AMateria& toCopy) : _type(toCopy._type)
{
	std::cout << BOLD PB "[AMateria " UNDERLINE << this->_type << RESET "]"
			  << PB " copy created" RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& toCopy)
{
	if (this != &toCopy)
		this->_type = toCopy._type;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << BOLD RED "[AMateria " UNDERLINE << this->_type << RESET BOLD
			  << RED "]" RESET RED " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Getter ] -----------------------------
*/
std::string const&	AMateria::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *"
				  << std::endl;
	}
	else if (this->_type == "cure")
	{
		std::cout << "* heals " << target.getName() << "'s wounds *"
				  << std::endl;
	}
}
