/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 04:17:17 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << BOLD GREEN "[Dog " << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[Dog " << this->_type << "]" RESET
			  << PG " created" RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}

Dog::~Dog()
{
	std::cout << BOLD RED "[Dog " << this->_type << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Dog::makeSound()
{
	std::cout << LIGHT_GRAY2 "[Doggie] " RESET "Woof woof..." << std::endl;
}
