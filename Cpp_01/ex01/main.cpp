/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/05/20 17:13:08 by annabrag         ###   ########.fr       */
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
	Horde = nullptr;
	return (SUCCESS);
}
