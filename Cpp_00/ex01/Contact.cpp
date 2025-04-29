/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/28 23:26:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	// std::cout << "Contact: Constructor called :)" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact: Destructor called :(" << std::endl;
}

void	Contact::setContactInfo(std::string target, std::string newValue)
{
	if (target == "first_name")
		this->first_name = newValue;
	else if (target == "last_name")
		this->last_name = newValue;
	else if (target == "nickname")
		this->nickname = newValue;
	else if (target == "phone_nb")
		this->phone_nb = newValue;
	else if (target == "dark_secret")
		this->dark_secret = newValue;
}

std::string Contact::getContactInfo(std::string target) const
{
	if (target == "first_name")
		return (this->first_name);
	else if (target == "last_name")
		return (this->last_name);	
	else if (target == "nickname")
		return (this->nickname);
	else if (target == "phone_nb")
		return (this->phone_nb);
	else if (target == "dark_secret")
		return (this->dark_secret);
	return ("");
}
