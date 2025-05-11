/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 05:18:25 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	_Brain = new Brain();
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[" << this->_type << "]" RESET << PG " copy created"
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
	std::cout << BOLD PO "[" << this->_type << "]" RESET << RED " destroyed"
			  << RESET << std::endl;
}

std::string		Cat::getType() const
{
	return (this->_type);
}

void	Cat::makeSound() const
{
	std::cout << PP "[Cat] " RESET "Meooow... :3" << std::endl;
}
