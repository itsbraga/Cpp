/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:55 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/06 00:23:40 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SUCCESS 0
# define FAILURE 1

# include <string>
# include <iomanip>
# include <iostream>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void);
		void	exitPhoneBook(void);

	private:
		Contact	array[8];
		size_t	i = 0;
		size_t	ContactAmount = 0;
};

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		Contact::setContactInfo(std::string target, std::string newValue);
		std::string	Contact::getContactInfo(std::string target);

	private:
		std::string 	first_name;
		std::string 	last_name;
		std::string 	nickname;
		std::string 	phone_nb;
		std::string 	dark_secret;
};

#endif