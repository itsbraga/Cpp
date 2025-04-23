/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:06:09 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 00:35:43 by panther          ###   ########.fr       */
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
	Harl		Harl;

	if (argc != 2)
	{
		std::cerr << BOLD RED "Invalid argument(s)" << std::endl;
		std::cout << PY "Usage: " RESET << "./harlFilter <level>"
				  << std::endl;
		return (FAILURE);
	}
	Harl.filter(argv[1]);
	return (SUCCESS);
}
