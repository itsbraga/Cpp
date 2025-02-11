/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:22:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/16 18:14:49 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	__showMenu(void)
{
	std::cout << BOLD PP CMD_HEADER << BAR_EMPT << "\n" << FRONT
			  << BOLD PY "ADD: " RESET << "register a new contact"
			  << BOLD PP BACK1 FRONT
			  << BOLD PY "SEARCH: " RESET << "display the given contact"
			  << BOLD PP BACK2 FRONT
			  << BOLD PY "EXIT: " RESET << "exit the phonebook "
			  << "and all contacts are deleted" << BOLD PP BACK3
			  << BAR_EMPT CMD_BOTTOM RESET << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	artemisBook;
	std::string	input;
	std::string	choice[] = {"ADD", "SEARCH", "EXIT"};
	void		(PhoneBook::*f[])(void) = {&PhoneBook::addContact,
											&PhoneBook::searchContact,
											&PhoneBook::exitPhoneBook};

	if (argc > 1)
	{
		std::cout << ERR_PREFIX "Program cannot contain arguments" << std::endl;
		return (FAILURE);
	}

	std::cout << PINK WELCOME ASCII_ART RESET << std::endl;
	std::cout << BOLD PP "Available commands: " RESET << "ADD, SEARCH, EXIT\n"
			  << std::endl;

	while (true)
	{
		bool validOption = false;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		for (size_t i = 0; i < 3; i++)
		{
			if (input == choice[i])
			{
				(artemisBook.*f[i])();
				validOption = true;
				break;
			}
		}
		if (validOption == false)
		{
			if (input == "menu")
				__showMenu();
			else
				std::cout << ERR_PREFIX "Invalid option, please try again "
						<< "or type 'menu' to get all the options" << std::endl;
		}
		input.clear();
	}
	return (SUCCESS);
}
