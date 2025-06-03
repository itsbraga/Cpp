/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/06/03 18:59:18 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 6;
	Zombie*	Horde;

	if (N < 0 || N > 1000)
		return (FAILURE);

	Horde = zombieHorde(N, "Elon Musk");

	for (int i = 0; i < N; i++)
		Horde[i].announce();
	
	delete [] Horde;
	return (SUCCESS);
}
