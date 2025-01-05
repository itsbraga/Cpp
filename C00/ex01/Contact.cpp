/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/05 21:30:56 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	std::cout << "Contact: Constructor called :)" << std::endl;
	return ;
};

Contact::~Contact(void)
{
	std::cout << "Contact: Destructor called :(" << std::endl;
	return ;
};

std::string Contact::getContactInfo(std::string target)
{
	if (this->first_name == target)
		return (this->first_name);
	else if (this->last_name == target)
		return (this->last_name);	
	else if (this->nickname == target)
		return (this->nickname);
	else if (this->phone_nb == target)
		return (this->phone_nb);
	else if (this->dark_secret == target)
		return (this->dark_secret);
	else
		return (NULL);
}

void	Contact::setContactInfo(std::string target, std::string newValue)
{
	if (this->first_name == target)
		this->first_name = newValue;
	else if (this->last_name == target)
		this->last_name = newValue;
	else if (this->nickname == target)
		this->nickname = newValue;
	else if (this->phone_nb == target)
		this->phone_nb = newValue;
	else if (this->dark_secret == target)
		this->dark_secret = newValue;
}
