/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/22 18:22:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Animal::Animal()
{
	std::cout << BOLD BLUE "[Animal]" RESET BLUE " created" << RESET << std::endl;
	this->_type = "None";
}

Animal::Animal(const Animal& toCopy)
{
	std::cout << BOLD PB "[Animal " << this->_type << "]" RESET
			  << PB " copy created" RESET << std::endl;
	*this = toCopy;
}

Animal&	Animal::operator=(const Animal& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	if (this != &toCopy)
		this->_type = toCopy._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BOLD RED "[Animal " UNDERLINE << this->_type << RESET BOLD RED
			  << "]" RESET RED " destroyed" RESET << std::endl;
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
