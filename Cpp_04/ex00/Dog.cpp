/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/23 23:12:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET GREEN " created"
			  << RESET << std::endl;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[" << this->_type << "]" RESET PG " copy created"
			  << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}

Dog::~Dog()
{
	std::cout << BOLD ORANGE "[" << this->_type << "]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

/*
	----------------------------- [ Getter ] -----------------------------
*/
const std::string&	Dog::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	Dog::makeSound() const
{
	std::cout << PURPLE "[Dog] " RESET "Woof woof 🐶" << std::endl;
}
