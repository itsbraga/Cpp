/* ---------------------------------------------------------------_************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:54:41 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 16:04:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ---------------------------------------------------------------_************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "../colors.hpp"

static void	__print_ptr_copy(std::string string)
{
	std::cout << BOLD RED UNDERLINE "LOCAL2:" RESET << std::endl;
	std::cout << BOLD PP "mem addr: " RESET << &string << std::endl;
	std::cout << BOLD PY "content: " RESET << string << "\n\n";
}

static void	__print_modified_ptr_copy(std::string string)
{
	std::cout << BOLD PB "[ string ]" RESET << std::endl;

	string = "Hey bro";
	std::cout << BOLD RED UNDERLINE "LOCAL:" RESET << std::endl;
	std::cout << BOLD PP "mem addr: " RESET << &string << std::endl;
	std::cout << BOLD PY "content: " RESET << string << "\n\n";
}

static void	__print_ptr(const std::string* stringPTR)
{
	std::cout << BOLD PG "[ stringPTR ]" RESET << std::endl;

	std::cout << BOLD PP "mem addr: " RESET << stringPTR << std::endl;
	std::cout << BOLD PY "content: " RESET << *stringPTR << "\n\n";
}

static void	__print_ref(const std::string& stringREF)
{
	std::cout << BOLD PGG "[ stringREF ]" RESET << std::endl;

	std::cout << BOLD PP "mem addr: " RESET << &stringREF << std::endl;
	std::cout << BOLD PY "content: " RESET << stringREF << "\n\n";
}

/*
	A reference is like a constant pointer and is never NULL
*/
int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << BOLD PB "[ string ]" RESET << std::endl;
	std::cout << BOLD PP "mem addr: " RESET << &string << std::endl;
	std::cout << BOLD PY "content: " RESET << string << "\n\n";
	__print_ptr(stringPTR);
	__print_ref(stringREF);	
	std::cout << std::endl;
	string = "That's what she said";
	std::cout << "--------------------------------" << std::endl;
	__print_modified_ptr_copy(string);
	__print_ptr_copy(string);
	std::cout << BOLD RED UNDERLINE "OUTSITE FUNCTION:" RESET << std::endl;
	std::cout << BOLD PP "mem addr: " RESET << &string << std::endl;
	std::cout << BOLD PY "content: " RESET << string << std::endl;
	std::cout << "--------------------------------\n\n";
	std::cout << std::endl;
	__print_ptr(stringPTR);
	__print_ref(stringREF);
	return (EXIT_SUCCESS);
}
