/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/15 14:49:46 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << BOLD PY "-----[ ClapTrap creation ]-----" RESET << std::endl;
	ClapTrap a("Brice2Nice");
	ClapTrap b("Anne-Sophie");
	ClapTrap c("Berangere");

	std::cout << BOLD PY "\n-----[ Basic attacks ]-----" RESET << std::endl;
	a.attack("Anne-Sophie");
	b.attack("Brice2Nice");
	c.attack("Brice2Nice");

	std::cout << BOLD PY "\n-----[ Taking damage ]-----" RESET << std::endl;
	a.takeDamage(5);
	b.takeDamage(10);
	c.takeDamage(0);

	std::cout << BOLD PY "\n-----[ Repairs ]-----" RESET << std::endl;
	a.beRepaired(2);
	b.beRepaired(20);
	c.beRepaired(0);

	std::cout << BOLD PY "\n-----[ Attacks until energy runs out ]-----" RESET
			  << std::endl;
	for (int i = 0; i < 12; ++i)
		a.attack("Berangere");

	std::cout << BOLD PY "\n-----[ Fatal damage ]-----" RESET << std::endl;
	b.takeDamage(100);

	std::cout << BOLD PY "\n-----[ Trying actions with 0 hit point or energy ]-----"
			  << RESET << std::endl;
	b.attack("Brice2Nice");
	b.beRepaired(5);

	std::cout << BOLD PY "\n-----[ Copy test ]-----" RESET << std::endl;
	ClapTrap d = a; // Copy constructor
	d.attack("Brice2Nice");
	ClapTrap e("Bernard");
	e = c; // Copy assignment operator
	e.attack("Anne-Sophie");

	std::cout << BOLD PY "\n-----[ End of program, destructors called ]-----" RESET
			  << std::endl;
	return (SUCCESS);
}
