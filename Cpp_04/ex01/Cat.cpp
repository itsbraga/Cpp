/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/22 18:01:54 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_Brain = new Brain();
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET GREEN " created"
			  << RESET << std::endl;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	this->_type = toCopy._type;
	this->_Brain = new Brain(*toCopy._Brain);
	std::cout << BOLD PG "[" << this->_type << "]" RESET PG " copy created"
			  << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& toCopy)
{
	if (this != &toCopy)
	{
		Animal::operator=(toCopy);
		delete this->_Brain;
		this->_Brain = NULL;
		this->_Brain = new Brain(*toCopy._Brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->_Brain;
	this->_Brain = NULL;
	std::cout << BOLD PO "[" << this->_type << "]" RESET PO " destroyed"
			  << RESET << std::endl;
}

/*
	----------------------------- [ Getters ] ----------------------------
*/
const std::string&	Cat::getType() const
{
	return (this->_type);
}

Brain*	Cat::getBrain() const
{
	return (this->_Brain);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	Cat::makeSound() const
{
	std::cout << PP "[Cat] " RESET "Meooow... 🐱" << std::endl;
}
