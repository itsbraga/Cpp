/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 16:59:56 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "None";
	std::cout << BOLD PG "[WrongAnimal]" RESET PG " created"
			  << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy) : _type(toCopy._type)
{
	std::cout << BOLD PGG "[WrongAnimal " << this->_type << "]" RESET
			  << PGG " copy created" RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& toCopy)
{
	if (this != &toCopy)
		this->_type = toCopy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLD RED "[WrongAnimal " << this->_type << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

const std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << LIGHT_GRAY2 ITAL "Meeeuuuh 🐮" RESET << std::endl;
}
