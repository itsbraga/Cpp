/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/21 17:39:24 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << BOLD PY "------[ FragTrap creation ]------" RESET << std::endl;
	FragTrap a("SDM");
	FragTrap b("Tiakola");
	FragTrap c("Luidji");

	std::cout << BOLD PY "\n------[ Basic attacks ]------" RESET << std::endl;
	a.attack("Tiakola");
	b.attack("SDM");
	c.attack("SDM");

	std::cout << BOLD PY "\n------[ Taking damage ]------" RESET << std::endl;
	a.takeDamage(5);
	b.takeDamage(10);
	c.takeDamage(0);
	c.highFivesGuys();

	std::cout << BOLD PY "\n------[ Repairs ]------" RESET << std::endl;
	a.beRepaired(2);
	b.beRepaired(20);
	b.highFivesGuys();
	c.beRepaired(0);

	std::cout << BOLD PY "\n------[ Attacks until energy runs out ]------" RESET
			  << std::endl;
	for (int i = 0; i < 32; ++i)
		a.attack("Luidji");

	std::cout << BOLD PY "\n------[ Fatal damage ]------" RESET << std::endl;
	b.takeDamage(100);

	std::cout << BOLD PY "\n------[ Trying actions with 0 hit point or energy ]------"
			  << RESET << std::endl;
	b.attack("SDM");
	b.beRepaired(5);

	std::cout << BOLD PY "\n------[ Copy test ]------" RESET << std::endl;
	FragTrap d = a; // Copy constructor
	d.attack("SDM");
	FragTrap e("Freeze Corleone");
	e = c; // Copy assignment operator
	e.attack("Tiakola");

	ClapTrap	*ptr = new FragTrap("Patrick");
	delete ptr;
	ptr = NULL;

	std::cout << BOLD PY "\n------[ End of program, destructors called ]------" RESET
			  << std::endl;
	return (SUCCESS);
}
