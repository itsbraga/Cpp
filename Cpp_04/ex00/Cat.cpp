/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/23 23:15:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET GREEN " created"
			  << RESET << std::endl;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[" << this->_type << "]" RESET PG " copy created"
			  << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}

Cat::~Cat()
{
	std::cout << BOLD PO "[" << this->_type << "]" RESET PO " destroyed"
			  << RESET << std::endl;
}

/*
	----------------------------- [ Getter ] -----------------------------
*/
const std::string&	Cat::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	Cat::makeSound() const
{
	std::cout << PP "[Cat] " RESET "Meooow... 🐱" << std::endl;
}
