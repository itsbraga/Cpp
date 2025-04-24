/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:36:21 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:21:18 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
	std::cout << BOLD PO "WEAPON" PG " [Constructor] " RESET << "called"
			  << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << BOLD PO "WEAPON" RED " [Destructor] " RESET << "called"
			  << std::endl;
}

void	Weapon::setType(const std::string& newType)
{
	if (type.empty() == false)
		this->type = newType;
}

std::string	const &	Weapon::getType(void)
{
	return (this->type);
}
