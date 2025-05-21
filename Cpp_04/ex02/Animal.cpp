/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:27:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Animal::Animal()
{
	this->_type = "None";
	std::cout << BOLD BLUE "[Animal]" RESET BLUE " created"
			  << RESET << std::endl;
}

Animal::Animal(const Animal& toCopy) : _type(toCopy._type)
{
	std::cout << BOLD PB "[Animal " << this->_type << "]" RESET
			  << PB " copy created" RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& toCopy)
{
	if (this != &toCopy)
		this->_type = toCopy._type;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
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
