/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/04/01 01:23:18 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << BOLD PG "[Constructor] " RESET << "a Zombie is born"
			  << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << BOLD RED "[Destructor] " RESET << this->name << " died"
			  << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argv;
	Zombie*	zombie;

	if (argc > 1)
		return (EXIT_FAILURE);
	zombie = newZombie("Einstein");
	zombie->announce();
	delete(zombie);
	randomChump("Yakitori");
	return (EXIT_SUCCESS);
}
