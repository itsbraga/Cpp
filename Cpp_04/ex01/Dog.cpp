/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/20 17:13:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_Brain = new Brain();
	std::cout << BOLD HOT_PINK "[" << this->_type << "]" RESET HOT_PINK
			  << " created" RESET << std::endl;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	this->_type = toCopy._type;
	this->_Brain = new Brain(*toCopy._Brain);
	std::cout << BOLD PINK "[" << this->_type << "]" RESET PINK
			  << " copy created" RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& toCopy)
{
	if (this != &toCopy)
	{
		Animal::operator=(toCopy);
		delete this->_Brain;
		// this->_Brain = nullptr;
		this->_Brain = new Brain(*toCopy._Brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_Brain;
	this->_Brain = nullptr;
	std::cout << BOLD ORANGE "[" << this->_type << "]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

const std::string&	Dog::getType() const
{
	return (this->_type);
}

void	Dog::makeSound() const
{
	std::cout << PURPLE "[Dog] " RESET "Woof woof 🐶" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->_Brain);
}
