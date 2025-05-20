/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:58:16 by panther           #+#    #+#             */
/*   Updated: 2025/05/20 16:44:56 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = nullptr;

	try
	{
		zombie = new Zombie;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << BOLD PY "Zombie : " RESET << e.what() << std::endl;
	}
	zombie->setName(name);
	return (zombie);
}
