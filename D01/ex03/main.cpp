/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:12:12 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon	club = Weapon("crude spiked club");
	HumanA	bob("Bob", club);

	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	club.setType("crude spiked club"); // reset for next Human

	HumanB	jim("Jim");

	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	return (SUCCESS);
}
