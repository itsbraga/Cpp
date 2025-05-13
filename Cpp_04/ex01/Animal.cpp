/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 17:02:32 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "None";
	std::cout << BOLD PG "[Animal]" RESET PG " created"
			  << RESET << std::endl;
}

Animal::Animal(const Animal& toCopy) : _type(toCopy._type)
{
	std::cout << BOLD PGG "[Animal " << this->_type << "]" RESET
			  << PGG " copy created" RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& toCopy)
{
	if (this != &toCopy)
		this->_type = toCopy._type;
	std::cout << BOLD PY "[Assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BOLD RED "[Animal " << this->_type << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

const std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	if (type.empty() == false)
		this->_type = type;
}

void	Animal::makeSound() const
{
	std::cout << LIGHT_GRAY2 ITAL "Booo..." RESET << std::endl;
}
