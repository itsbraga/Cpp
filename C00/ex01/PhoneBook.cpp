/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/07 21:59:44 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : Head(0), ContactAmount(0)
{
	std::cout << "PhoneBook: Constructor called :)" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook: Destructor called :(" << std::endl;
	return ;
}

void	PhoneBook::addContact(void)
{
	size_t		f_i;
	std::string	input;
	std::string	field[] = {"first_name", "last_name", "nickname",
							"phone_nb", "dark_secret"};

	for (f_i = 0; f_i < 5; f_i++)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		if (isValidInput(input, field[f_i]) == true)
			this->array[this->Head].setContactInfo(field[f_i], input);
		else
		{
			std::cout << ERR_PREFIX "Invalid input" << std::endl;
			f_i--;
		}
		input.clear();
	}
	this->Head = (this->Head + 1) % MAX_CONTACTS; // incremente en circulaire
	if (this->ContactAmount < MAX_CONTACTS)
		this->ContactAmount++;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	int			index;

	showContactList();
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		if (input == "menu")
			return ;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (std::isdigit(input[i]) == true)
				index = std::atoi(input.c_str());
			else
				std::cout << ERR_PREFIX "Only numbers are allowed" << std::endl;
		}
		if (index < 0 || index > this->ContactAmount)
			std::cout << ERR_PREFIX "Index is out of range" << std::endl;
		else
		{
			showContact(index - 1);
			return ;
		}
	}
}

void	PhoneBook::exitPhoneBook(void)
{
	std::cout << "See you later!" << std::endl;
	std::exit(SUCCESS);
}
