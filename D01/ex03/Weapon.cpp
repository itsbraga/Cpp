/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:36:21 by panther           #+#    #+#             */
/*   Updated: 2025/05/22 19:38:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
	std::cout << BOLD PO "WEAPON" PG " [Constructor] " RESET << "called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << BOLD PO "WEAPON" RED " [Destructor] " RESET << "called" << std::endl;
}

void	Weapon::setType(const std::string& newType)
{
	this->_type = newType;
}

const std::string&	Weapon::getType() const
{
	return (this->_type);
}
