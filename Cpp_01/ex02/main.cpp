/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:54:41 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 14:18:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "colors.hpp"

/*
	A reference is like a constant pointer and is never NULL
*/
int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << BOLD PP "Mem addr:" RESET
			  << PINK " (1) &string " RESET << &string
			  << PO " (2) stringPTR " RESET << stringPTR
			  << PB " (3) &stringREF " RESET << &stringREF << std::endl;
	std::cout << BOLD PY "Values:" RESET
			  << PINK " (1) string " RESET << string
			  << PO " (2) *stringPTR " RESET << *stringPTR
			  << PB " (3) stringREF " RESET << stringREF << std::endl;
	return (SUCCESS);
}
