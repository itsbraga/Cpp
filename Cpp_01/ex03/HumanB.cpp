/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:37:01 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:19:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << BOLD PINK "HUMAN_B" PG " [Constructor] " RESET << "called"
			  << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << BOLD PINK "HUMAN_B" RED " [Destructor] " RESET << "called"
			  << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their "
				  << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with!"
				  << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
