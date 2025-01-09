/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showContacts.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:17:50 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/09 18:18:18 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	__truncateStr(std::string str)
{
	std::string	substracted;

	if (str.length() > 10)
	{
		substracted = str.substr(0, 9);
		str.push_back('.');
	}
	else
		return (str);
	return (substracted);
}

void	PhoneBook::showContactList(void)
{
	std::cout << BANNER << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX"
			  << "|" << std::setw(10) << "FIRST_NAME"
			  << "|" << std::setw(10) << "LAST_NAME"
			  << "|" << std::setw(10) << "NICKNAME"
			  << "|" << std::endl;

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
	std::cout << BANNER << std::endl;
}

void	PhoneBook::showContact(size_t choice)
{
	std::cout << std::setw(14) << "FIRST_NAME|" << std::setw(14)
			  << this->array[choice].getContactInfo("first_name") << std::endl;
	std::cout << std::setw(14) << "LAST_NAME|" << std::setw(14)
			  << this->array[choice].getContactInfo("last_name") << std::endl;
	std::cout << std::setw(14) << "NICKNAME|" << std::setw(14)
			  << this->array[choice].getContactInfo("nickname") << std::endl;
	std::cout << std::setw(14) << "PHONE NUMBER|" << std::setw(14)
			  << this->array[choice].getContactInfo("phone_nb") << std::endl;
	std::cout << std::setw(14) << "DARKEST SECRET|" << std::setw(14)
			  << this->array[choice].getContactInfo("dark_secret") << std::endl;
}
