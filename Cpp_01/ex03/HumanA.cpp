/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:36:42 by panther           #+#    #+#             */
/*   Updated: 2025/04/01 02:08:00 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << BOLD PINK "HUMAN_A" PG " [Constructor] " RESET << "called"
			  << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << BOLD PINK "HUMAN_A" RED " [Destructor] " RESET << "called"
			  << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType()
			  << std::endl;
}
