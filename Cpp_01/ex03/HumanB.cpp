/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:37:01 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:20:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
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
	if (this->weapon != NULL)
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
