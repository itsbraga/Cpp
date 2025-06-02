/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/28 23:26:23 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : head(0), contactAmount(0)
{
	// std::cout << "PhoneBook: Constructor called :)" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBook: Destructor called :(" << std::endl;
}

void	PhoneBook::addContact()
{
	size_t		i;
	std::string	input;
	std::string	field[] = {"first_name", "last_name", "nickname",
							"phone_nb", "dark_secret"};

	for (i = 0; i < 5; i++)
	{
		std::cout << "Enter " << field[i] << " : ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		if (checkInput(input, field[i]) == true)
			this->array[this->head].setContactInfo(field[i], input);
		else
			i--;
		input.clear();
	}
	this->head = (this->head + 1) % MAX_CONTACTS; // incremente en circulaire
	if (this->contactAmount < MAX_CONTACTS)
		this->contactAmount++;
	std::cout << BOLD GREEN "\nContact added successfully!\n" RESET << std::endl;
}

void	PhoneBook::searchContact()
{
	int			index;
	std::string	input;

	if (this->contactAmount == 0)
	{
		std::cout << ERR_PREFIX "This Phonebook is empty" << std::endl;
		return ;
	}
	showContactList();
	std::cout << "Enter index (1-" << contactAmount << ") or 'back' to return\n"
			  << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		if (input == "back")
			return ;
		else if (input.length() == 1 && std::isdigit(input[0]) != 0)
		{
			index = std::atoi(input.c_str());
			if (index > 0 && index <= this->contactAmount)
			{
				showContact(index - 1);
				return ;
			}
			std::cout << ERR_PREFIX "Invalid index" << std::endl;
		}
		else
			std::cout << ERR_PREFIX "Invalid input, please try again"
					  << std::endl;
	}
}

void	PhoneBook::exitPhoneBook()
{
	std::cout << BOLD BLUE "Goodbye!" RESET << std::endl;
	std::exit(SUCCESS);
}
