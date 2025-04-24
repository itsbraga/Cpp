/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:55 by annabrag          #+#    #+#             */
/*   Updated: 2025/02/05 15:48:08 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1
# define ERR_PREFIX BOLD RED "Error: " RESET
# define MAX_CONTACTS 8

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iomanip>
# include <iostream>
# include <cstdlib>
# include "custom.hpp"

/******************************************************************************\
 * CLASSES
\******************************************************************************/

class Contact
{
	public:
	
		Contact(void);
		~Contact(void);

		void			setContactInfo(std::string target, std::string newValue);
		std::string		getContactInfo(std::string target) const;


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

		void		addContact(void);
		void		searchContact(void);
		void		exitPhoneBook(void);
		void		showContactList(void);
		void		showContact(size_t choice);


	private:
	
		Contact		array[MAX_CONTACTS];
		size_t		head;
		int			contactAmount;
};

/******************************************************************************\
 * TOOLS
\******************************************************************************/

bool	checkInput(std::string input, std::string field);

#endif