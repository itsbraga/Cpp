/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:03:52 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie;

	zombie = newZombie("Einstein");
	zombie->announce();
	delete(zombie);
	randomChump("Yakitori");

	return (SUCCESS);
}
