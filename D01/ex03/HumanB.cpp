/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:37:01 by panther           #+#    #+#             */
/*   Updated: 2025/05/22 19:38:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << BOLD PINK "HUMAN_B" PG " [Constructor] " RESET << "called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << BOLD PINK "HUMAN_B" RED " [Destructor] " RESET << "called" << std::endl;
}

void	HumanB::attack()
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
