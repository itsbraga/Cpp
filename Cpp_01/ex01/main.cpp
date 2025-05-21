/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:33 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 19:40:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 6;
	Zombie*	Horde;

	Horde = zombieHorde(N, "Elon Musk");

	for (int i = 0; i < N; i++)
		Horde[i].announce();
	
	delete [] Horde;
	Horde = NULL;
	return (SUCCESS);
}
