/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:06:09 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:02:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	// std::cout << BOLD PG "[Constructor] " RESET << "called" << std::endl;
}

Harl::~Harl(void)
{
	// std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
}

int	main(int argc, char **argv)
{
	Harl	Harl;

	if (argc != 2)
	{
		std::cerr << BOLD RED "Error" PY << std::endl;
		std::cout << "Usage: " RESET << argv[0] << " <level>" << std::endl;
		return (FAILURE);
	}
	Harl.complain(argv[1]);
	return (SUCCESS);
}
