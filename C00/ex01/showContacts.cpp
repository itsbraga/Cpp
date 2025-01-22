/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showContacts.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:17:50 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/16 18:26:46 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	__truncateStr(std::string str)
{
	std::string	substracted;

	if (str.length() > 10)
	{
		substracted = str.substr(0, 9);
		substracted.push_back('.');
	}
	else
		return (str);
	return (substracted);
}

void	PhoneBook::showContactList(void)
{
	std::cout << TOP_BANNER << std::endl;
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First name"
			  << "|" << std::setw(10) << "Last name"
			  << "|" << std::setw(10) << "Nickname"
			  << "|\n" << BOTTOM_BANNER << std::endl;

	for (int counter = 0; counter < this->contactAmount; counter++)
	{
		std::cout << "|" << std::setw(10) << counter + 1 // get info index;
				  << "|" << std::setw(10)
				  << __truncateStr(this->array[counter].getContactInfo("first_name"))
				  << "|" << std::setw(10)
				  << __truncateStr(this->array[counter].getContactInfo("last_name"))
				  << "|" << std::setw(10)
				  << __truncateStr(this->array[counter].getContactInfo("nickname"))
				  << "|" << std::endl;
	}
	std::cout << BOTTOM_BANNER << "\n" << std::endl;
}

void	PhoneBook::showContact(size_t choice)
{
	std::cout << std::setw(16) << BOLD PINK "\n[First name]" RESET << "\t\t"
			  << this->array[choice].getContactInfo("first_name") << std::endl;
	std::cout << std::setw(16) << BOLD PINK "[Last name]" RESET << "\t\t"
			  << this->array[choice].getContactInfo("last_name") << std::endl;
	std::cout << std::setw(16) << BOLD PINK "[Nickname]" RESET << "\t\t"
			  << this->array[choice].getContactInfo("nickname") << std::endl;
	std::cout << std::setw(16) << BOLD PINK "[Phone number]" RESET << "\t\t"
			  << this->array[choice].getContactInfo("phone_nb") << std::endl;
	std::cout << std::setw(16) << BOLD PINK "[Darkest secret]" RESET << "\t"
			  << this->array[choice].getContactInfo("dark_secret") << "\n"
			  << std::endl;
}
