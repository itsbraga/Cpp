/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 04:21:10 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "None";
	std::cout << BOLD PG "[Animal " << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

Animal::Animal(const Animal& toCopy)
{
	std::cout << BOLD PGG "[Animal " << this->_type << "]" RESET
			  << PGG " created" RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& toCopy)
{
	if (this != &toCopy)
		this->_type = toCopy._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BOLD RED "[Animal " << this->_type << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound()
{
	if (this->_type.empty() == true)
		return ;
	if (this->_type.compare("Dog") )
}
