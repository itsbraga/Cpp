/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/04/01 01:31:40 by panther          ###   ########.fr       */
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
	int		N = 8;
	Zombie*	Horde;

	if (argc > 1)
		return (EXIT_FAILURE);
	Horde = zombieHorde(N, "Elon Musk");
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] Horde;
	return (EXIT_SUCCESS);
}
