/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/07 22:03:22 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << BOLD PY "======[ ScavTrap creation ]======" RESET << std::endl;
	ScavTrap a("Damso");
	ScavTrap b("Kalash");
	ScavTrap c("Booba");

	std::cout << BOLD PY "\n======[ Basic attacks ]======" RESET << std::endl;
	a.attack("Kalash");
	b.attack("Damso");
	c.attack("Damso");

	std::cout << BOLD PY "\n======[ Taking damage ]======" RESET << std::endl;
	a.takeDamage(5);
	b.takeDamage(10);
	c.takeDamage(0);

	std::cout << BOLD PY "\n======[ Repairs ]======" RESET << std::endl;
	a.beRepaired(2);
	b.beRepaired(20);
	c.beRepaired(0);

	std::cout << BOLD PY "\n======[ Attacks until energy runs out ]======" RESET
			  << std::endl;
	for (int i = 0; i < 52; ++i)
		a.attack("Booba");

	std::cout << BOLD PY "\n======[ Fatal damage ]======" RESET << std::endl;
	b.takeDamage(100);

	std::cout << BOLD PY "\n======[ Trying actions with 0 hit point or energy ]======"
			  << RESET << std::endl;
	b.attack("Damso");
	b.beRepaired(5);

	std::cout << BOLD PY "\n======[ Copy test ]======" RESET << std::endl;
	ScavTrap d = a; // copy constructor
	d.attack("Damso");
	ScavTrap e("Benash");
	e = c; // assignment operator
	e.attack("Kalash");

	std::cout << BOLD PY "\n======[ End of program, destructors called ]======" RESET
			  << std::endl;
	return (SUCCESS);
}
