/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:36:42 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:11:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
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
	std::cout << this->_name << " attacks with their "
			  << this->_weapon.getType() << std::endl;
}
