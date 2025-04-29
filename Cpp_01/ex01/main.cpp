/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:04:02 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 15;
	Zombie*	Horde;

	Horde = zombieHorde(N, "Elon Musk");

	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] Horde;

	return (SUCCESS);
}
