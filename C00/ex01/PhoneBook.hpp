/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:55 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/06 22:09:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SUCCESS 0
# define FAILURE 1

# define ERR_PREFIX BOLD RED "Error: " RESET
# define BANNER "________________________________________"

# include <string>
# include <iomanip>
# include <iostream>
# include <cstdlib>
# include "colors.hpp"

bool	isValidInput(std::string input, std::string field);

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void			setContactInfo(std::string target, std::string newValue);
		std::string		getContactInfo(std::string target);

	private:
		std::string 	first_name;
		std::string 	last_name;
		std::string 	nickname;
		std::string 	phone_nb;
		std::string 	dark_secret;
};

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void);
		void	exitPhoneBook(void);

	private:
		Contact		array[8];
		size_t		Head;
		int			ContactAmount;
		void		showContactList(void);
		void		showContact(size_t choice);
};

#endif