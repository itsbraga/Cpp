/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/06 22:06:47 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook: Constructor called :)" << std::endl;
	return ;
};

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook: Destructor called :(" << std::endl;
	return ;
};

void	PhoneBook::addContact(void)
{
	size_t		f_i;
	std::string	input;
	std::string	field[] = {"first_name", "last_name", "nickname",
							"phone_nb", "dark_secret"};

	Head = 0;
	ContactAmount = 0;
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
			// this->Head--;
		}
		input.clear();
	}
	this->Head++; // ?
	if (this->ContactAmount < 8)
		this->ContactAmount++;
	if (this->Head == 8)
		this->Head = this->Head % 8;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	size_t		i;
	int			index;

	showContactList();
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		if (input == "menu")
			return ;
		for (i = 0; i < input.length(); i++)
		{
			if (std::isdigit(input[i]) == true)
			{
				index = std::atoi(input.c_str());
			}
			else
				std::cout << ERR_PREFIX "Only numbers are allowed" << std::endl;
		}
		if (index < 0 || index > this->ContactAmount)
			std::cout << ERR_PREFIX "Index is out of range" << std::endl;
		else
			showContact(index - 1);
	}
}

void	PhoneBook::exitPhoneBook(void)
{
	std::cout << "See you later!" << std::endl;
	std::exit(SUCCESS);
}
