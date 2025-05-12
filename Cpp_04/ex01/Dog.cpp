/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/12 20:37:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_Brain = new Brain();
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[ " << this->_type << "]" RESET << PG " copy created"
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
	delete this->_Brain;
	std::cout << BOLD ORANGE "[" << this->_type << "]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

std::string		Dog::getType() const
{
	return (this->_type);
}

void	Dog::makeSound() const
{
	std::cout << PURPLE "[Doggie] " RESET "Woof woof..." << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->_Brain);
}
