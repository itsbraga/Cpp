/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:06:09 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:05:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
