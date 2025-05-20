/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:51:18 by panther           #+#    #+#             */
/*   Updated: 2025/05/20 17:13:05 by annabrag         ###   ########.fr       */
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
	if (name.empty() == true)
		return ;
	this->_name = name;
}

const std::string	Zombie::getName() const
{
	return (this->_name);
}
