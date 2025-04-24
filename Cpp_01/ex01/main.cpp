/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:07:29 by annabrag         ###   ########.fr       */
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
	int		N = 8;
	Zombie*	Horde;

	Horde = zombieHorde(N, "Elon Musk");
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] Horde;
	return (SUCCESS);
}
