/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:17:49 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:21:06 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << BOLD BLUE "[AMateria]" << this->_type << RESET BLUE " created"
			  << RESET << std::endl;
}

AMateria::AMateria(const AMateria& toCopy) : _type(toCopy._type)
{
	std::cout << BOLD PB "[AMateria " << this->_type << "]" RESET
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

const std::string&	AMateria::getType() const
{
	return (this->_type);
}
