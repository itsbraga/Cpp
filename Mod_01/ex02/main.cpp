/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:54:41 by panther           #+#    #+#             */
/*   Updated: 2025/04/01 01:46:07 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "colors.hpp"

/*
	A reference is like a constant pointer and is never NULL
*/
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		return (EXIT_FAILURE);

	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << BOLD PP "Memory addresses:" RESET << " (1) " << &string
			  << " (2) " << stringPTR << " (3) " << &stringREF
			  << std::endl;
	std::cout << BOLD PY "Values:" RESET << " (1) " << string
			  << " (2) " << *stringPTR << " (3) " << stringREF
			  << std::endl;
	return (EXIT_SUCCESS);
}
