/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:22:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/09 16:09:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	artemisBook;
	std::string	input;
	bool		validOption = false;
	std::string	choice[] = {"ADD", "SEARCH", "EXIT"};
	void		(PhoneBook::*f[])(void) = {&PhoneBook::addContact,
											&PhoneBook::searchContact,
											&PhoneBook::exitPhoneBook};

	if (argc > 1)
		return (FAILURE);

	std::cout << "Welcome to ARTEMIS PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
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
			std::cout << ERR_PREFIX "Invalid option, please try again" << std::endl;
				// print options
		input.clear();
	}
	return (SUCCESS);
}
