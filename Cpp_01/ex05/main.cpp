/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:06:09 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 18:48:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harl;

	if (argc != 2)
	{
		std::cerr << BOLD RED "Error" YELLOW << std::endl;
		std::cout << "Usage: " RESET << argv[0] << " <level>" << std::endl;
		showMenu();
		return (FAILURE);
	}
	Harl.complain(argv[1]);
	return (SUCCESS);
}
