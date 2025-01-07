/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:36:10 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/07 22:00:21 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	isValidInput(std::string input, std::string field)
{
	if (input.empty() == true)
	{
		std::cout << ERR_PREFIX "All fields must be filled." << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (field == "phone_nb")
		{
			// add (+33) number prefix verif
			// add - and space verif
			if (std::isdigit(input[i]) == true)
				return (true);
		}
		else
		{
			if (i == 0)
			{
				if (std::isspace(input[i]) == true || input[i] == '-')
				{
					std::cout << ERR_PREFIX "Unallowed character" << std::endl;
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

static std::string	__truncStr(std::string target)
{
	std::string	substracted;

	if (target.length() > 10)
	{
		substracted = target.substr(0, 9);
		target.push_back('.');
	}
	else
		return (target);
	return (substracted);
}

void	PhoneBook::showContactList(void)
{
	std::cout << BANNER << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST_NAME";
	std::cout << "|" << std::setw(10) << "LAST_NAME" << "|" << std::setw(10) << "NICKNAME";
	std::cout << "|" << std::endl;

	for (int counter = 0; counter < this->ContactAmount; counter++)
	{
		std::cout << "|" << std::setw(10) << counter + 1; // get info index;
		std::cout << "|" << std::setw(10) << __truncStr(this->array[counter].getContactInfo("first_name"));
		std::cout << "|" << std::setw(10) << __truncStr(this->array[counter].getContactInfo("last_name"));
		std::cout << "|" << std::setw(10) << __truncStr(this->array[counter].getContactInfo("nickname"));
		std::cout << "|" << std::endl << BANNER << std::endl;
	}
}

void	PhoneBook::showContact(size_t choice)
{
	std::cout << std::setw(14) << "FIRST_NAME|";
	std::cout << std::setw(14) << this->array[choice].getContactInfo("first_name") << std::endl;
	std::cout << std::setw(14) << "LAST_NAME|";
	std::cout << std::setw(14) << this->array[choice].getContactInfo("last_name") << std::endl;
	std::cout << std::setw(14) << "NICKNAME|";
	std::cout << std::setw(14) << this->array[choice].getContactInfo("nickname") << std::endl;;
	std::cout << std::setw(14) << "PHONE NUMBER|";
	std::cout << std::setw(14) << this->array[choice].getContactInfo("phone_nb") << std::endl;;
	std::cout << std::setw(14) << "DARKEST SECRET|";
	std::cout << std::setw(14) << this->array[choice].getContactInfo("dark_secret") << std::endl;;
}
