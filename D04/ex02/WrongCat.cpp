/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:29 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 17:59:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	this->_Brain = new Brain();
	std::cout << BOLD GREEN "[" << this->_type << "]" RESET GREEN " created"
			  << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& toCopy) : WrongAnimal(toCopy)
{
	std::cout << BOLD PG "[" << this->_type << "]" RESET PG " copy created"
			  << RESET << std::endl;
	*this = toCopy;
}

WrongCat&	WrongCat::operator=(const WrongCat& toCopy)
{
	if (this != &toCopy)
	{
		WrongAnimal::operator=(toCopy);
		this->_Brain = new Brain(*toCopy._Brain);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << BOLD PO "[" << this->_type << "]" RESET PO " destroyed"
			  << RESET << std::endl;
	delete this->_Brain;
	this->_Brain = NULL;
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
