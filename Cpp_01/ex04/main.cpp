/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:16:57 by panther           #+#    #+#             */
/*   Updated: 2025/04/29 00:05:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << BOLD RED "Error\n" PY;
		std::cout << "Usage: " RESET << argv[0] << " <filename> <s1> <s2>\n";
		return (FAILURE);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	openAndReplace(filename.c_str(), s1.c_str(), s2.c_str());
	return (SUCCESS);
}

