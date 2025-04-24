/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:07:53 by annabrag         ###   ########.fr       */
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

int	main(void)
{
	Zombie*	zombie;

	zombie = newZombie("Einstein");
	zombie->announce();
	delete(zombie);
	randomChump("Yakitori");
	return (SUCCESS);
}
