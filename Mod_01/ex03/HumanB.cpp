/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:37:01 by panther           #+#    #+#             */
/*   Updated: 2025/04/01 02:14:38 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
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
	if (this->weapon != nullptr)
		std::cout << this->name << " attacks with their " << this->weapon->getType()
				  << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with!"
				  << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
