/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:35:19 by panther           #+#    #+#             */
/*   Updated: 2025/05/23 23:33:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
WrongAnimal::WrongAnimal()
{
	std::cout << BOLD PG "[WrongAnimal]" RESET PG " created" << RESET << std::endl;
	this->_type = "(null)";
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy)
{
	if (this->_type == "(null)")
		std::cout << BOLD PGG "[WrongAnimal]" RESET PGG " copy created" RESET << std::endl;
	else
		std::cout << BOLD PGG "[WrongAnimal " << this->_type << "]" RESET PGG
				  << " copy created" RESET << std::endl;
	*this = toCopy;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	if (this != &toCopy)
		this->_type = toCopy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLD RED "[WrongAnimal " << this->_type << "]" RESET RED
			  << " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Getter ] -----------------------------
*/
const std::string&	WrongAnimal::getType() const
{
	return (this->_type);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	WrongAnimal::makeSound() const
{
	std::cout << LIGHT_GRAY2 ITAL "Bzzz" RESET << std::endl;
}
