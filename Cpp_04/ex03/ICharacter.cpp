/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:24:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/15 22:31:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	// for (int i = 0; i < 4; i++)
	// 	this->_inventory[i] = nullptr;
	std::cout << BOLD HOT_PINK "[ICharacter]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

ICharacter::ICharacter(const ICharacter& toCopy)
{
	std::cout << BOLD PINK "[ICharacter]" RESET PINK " copy created"
			  << RESET << std::endl;
}

ICharacter&		ICharacter::operator=(const ICharacter& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

ICharacter::~ICharacter()
{
	for (int j = 0; j < 4; j++)
		delete this->_inventory[j];
	std::cout << BOLD LIGHT_GRAY2 "[ICharacter]" RESET LIGHT_GRAY2 " destroyed"
			  << RESET << std::endl;
}
