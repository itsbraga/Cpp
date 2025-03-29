/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/03/29 22:53:24 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	// std::cout << "Zombie: " << PINK "[Constructor] " RESET << "called"
	// 		  << std::endl;
	std::cout << "Zombie: [Constructor] called" << std::endl;
}

Zombie::~Zombie(void)
{
	// std::cout << "Zombie: " << PB "[Destructor] " RESET << "called "
	// 		  << this->name << std::endl;
	std::cout << "Zombie: [Destructor] called " << this->name << std::endl;
}

int	main(void)
{
	Zombie*	zombie;

	zombie = newZombie("Einstein");
	zombie->announce();
	delete(zombie);
	randomChump("Yakitori");
}
