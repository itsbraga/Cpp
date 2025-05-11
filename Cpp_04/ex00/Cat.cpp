/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 04:17:39 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << BOLD GREEN "[Cat " << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	std::cout << BOLD PG "[Cat " << this->_type << "]" RESET
			  << PG " created" RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}

Cat::~Cat()
{
	std::cout << BOLD RED "[Cat " << this->_type << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Cat::makeSound()
{
	std::cout << PP "[Cat] " RESET "Meooow... :3" << std::endl;
}
