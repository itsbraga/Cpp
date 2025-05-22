/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/22 17:59:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Animal::Animal()
{
	this->_type = "None";
	std::cout << BOLD PG "[Animal]" RESET PG " created" << RESET << std::endl;
}

Animal::Animal(const Animal& toCopy)
{
	*this = toCopy;
	std::cout << BOLD PGG "[Animal " << this->_type << "]" RESET
			  << PGG " copy created" RESET << std::endl;
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

/*
	----------------------------- [ Getter ] -----------------------------
*/
const std::string&	Animal::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	Animal::makeSound() const
{
	std::cout << LIGHT_GRAY2 ITAL "Booo..." RESET << std::endl;
}
