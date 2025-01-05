/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/06 00:50:57 by pmateo           ###   ########.fr       */
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

bool	inputCheckSuccessfull(std::string input, std::string field)
{
	size_t	i;

	if (input.empty() == true)
	{
		std::cout << "Error: All fields must be filled." << std::endl;
		return (false);
	}
	for (i = 0; i < input.length(); i++)
	{
		if (field == "phone_nb")
		{
			// add +33 verif
			// add - + space verif
			if (std::isdigit(input[i]) == true)
				return (true);
		}
		else
		{
			if (i == 0)
			{
				if (std::isspace(input[i]) == true || input[i] == '-')
				{
					std::cout << "Unallowed character" << std::endl;
					break;
				}
			}
			else if (std::isalpha(input[i]) == true
						|| std::isspace(input[i]) == true || input[i] == '-')
				return (true);
		}
	}
	return (false);
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
		if (inputCheckSuccessfull(input, field[f_i]) == true)
			this->array[this->i].setContactInfo(field[f_i], input);
		else
		{
			std::cout << "Invalid input" << std::endl;
			this->i--;
		}
		input.clear();
	}
	this->i++;
	if (this->ContactAmount < 8)
		this->ContactAmount++;
	if (this->i == 8)
		this->i = this->i % 8;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	size_t		index;

	// print la liste de contacts
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			std::exit(FAILURE);
		index = std::atoi(input.c_str());
		if (index < 0 || index > this->ContactAmount)
		{
			std::cout << "Index is out of range" << std::endl;
			break;
		}
		if (input == "menu")
			return ;
	}
	// utiliser (iomanip) setw() << text
}

void	PhoneBook::exitPhoneBook(void)
{
	// std::cout << "See you later!" << std::endl
	std::exit(SUCCESS);
}
