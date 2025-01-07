/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:22:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/07 21:59:20 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	artemisBook;
	void		(PhoneBook::*f[])(void) = {&PhoneBook::addContact,
											&PhoneBook::searchContact,
											&PhoneBook::exitPhoneBook};
	bool		validOption = false;
	std::string	input;
	std::string	choice[] = {"ADD", "SEARCH", "EXIT"};

	if (argc > 1)
		return (FAILURE);
	while (true)
	{
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
