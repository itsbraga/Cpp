/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:27:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET PG " created"
			  << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& toCopy) : WrongAnimal(toCopy)
{
	std::cout << BOLD PG "[" << this->_type << "]" RESET << PG " copy created"
			  << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& toCopy)
{
	if (this != &toCopy)
		WrongAnimal::operator=(toCopy);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << BOLD PO "[" << this->_type << "]" RESET << RED " destroyed"
			  << RESET << std::endl;
}

/*
	----------------------------- [ Getter ] -----------------------------
*/
const std::string&	WrongCat::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	WrongCat::makeSound() const
{
	std::cout << PP "[WrongCat] " RESET "Roaaarrr 🦁" << std::endl;
}
