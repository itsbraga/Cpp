/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:26 by panther           #+#    #+#             */
/*   Updated: 2025/04/28 23:26:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << BOLD PG "[Constructor] " RESET << "a Zombie is born"
			  << std::endl;
}

Zombie::~Zombie()
{
	std::cout << BOLD RED "[Destructor] " RESET << this->_name << " died"
			  << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	if (name.empty() == false)
		this->_name = name;
}

const std::string	Zombie::getName() const
{
	return (this->_name);
}
