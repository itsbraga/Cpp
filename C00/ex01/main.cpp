/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:22:25 by pmateo            #+#    #+#             */
/*   Updated: 2025/01/05 22:54:03 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	artemisBook;
	void		(PhoneBook::*f[])(void) = {&PhoneBook::addContact,
											&PhoneBook::searchContact,
											&PhoneBook::exitPhoneBook};
	size_t		i;
	std::string	input;
	std::string	choice[] = {"ADD", "SEARCH", "EXIT"};

	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		for (i = 0; i < 3; i++)
		{
			if (input == choice[i])
			{
				(artemisBook.*f[i])();
				break;
			}
		}
		if (i == 3)
			std::cout << "Invalid option, please try again" << std::endl;
			// print options
		input.clear();
	}
}
