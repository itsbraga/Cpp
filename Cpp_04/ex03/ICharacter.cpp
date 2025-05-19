/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:24:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/19 16:26:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << BOLD HOT_PINK "[ICharacter]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

ICharacter::ICharacter(const ICharacter& toCopy)
{
	(void)toCopy;
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
	std::cout << BOLD LIGHT_GRAY2 "[ICharacter]" RESET LIGHT_GRAY2 " destroyed"
			  << RESET << std::endl;
}
