/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:36:42 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:38:42 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << BOLD PINK "HUMAN_A" PG " [Constructor] " RESET << "called"
			  << std::endl;
}

HumanA::~HumanA()
{
	std::cout << BOLD PINK "HUMAN_A" RED " [Destructor] " RESET << "called"
			  << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
			  << this->_weapon.getType() << std::endl;
}
