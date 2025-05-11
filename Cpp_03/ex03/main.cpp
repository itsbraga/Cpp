/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/11 04:31:22 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << BOLD PY "======[ DiamondTrap creation ]======" RESET << std::endl;
	DiamondTrap	a("Nicki Minaj");
	DiamondTrap	b("Rihanna");
	DiamondTrap c("Megan Thee Stallion");

	std::cout << BOLD PY "\n======[ Who am I ]======" RESET << std::endl;
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	
	std::cout << BOLD PY "\n======[ ScavTrap attacks ]======" RESET << std::endl;
	a.attack("Rihanna");
	b.attack("Nicki Minaj");
	c.attack("Nicki Minaj");

	std::cout << BOLD PY "\n======[ Taking damage ]======" RESET << std::endl;
	a.takeDamage(50);
	b.takeDamage(20);
	c.takeDamage(5);

	std::cout << BOLD PY "\n======[ Repairs ]======" RESET << std::endl;
	a.beRepaired(30);
	b.beRepaired(50);
	c.beRepaired(0);

	std::cout << BOLD PY "\n======[ ScavTrap and FragTrap abilities ]======" RESET << std::endl;
	a.guardGate();
	b.highFivesGuys();

	std::cout << BOLD PY "\n======[ Attacks until energy runs out ]======" RESET
			  << std::endl;
	for (int i = 0; i < 52; ++i)
		a.attack("Megan Three Stallion");

	std::cout << BOLD PY "\n======[ Fatal damage ]======" RESET << std::endl;
	b.takeDamage(100);

	std::cout << BOLD PY "\n======[ Copy test ]======" RESET << std::endl;
	DiamondTrap d = a; // Copy constructor
	d.whoAmI();
	DiamondTrap e("Jacques");
	e = b; // Assignment operator
	e.whoAmI();

	ClapTrap	*ptr = new DiamondTrap("Bob");
	delete ptr;

	std::cout << BOLD PY "\n======[ End of program, destructors called ]======" RESET
			  << std::endl;
	return (SUCCESS);
}
