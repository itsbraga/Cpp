/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:55 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/16 18:38:42 by art3mis          ###   ########.fr       */
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

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iomanip>
# include <iostream>
# include <cstdlib>
# include "Contact.hpp"
# include "colors.hpp"

/******************************************************************************\
 * STRUCT for HISTORY
\******************************************************************************/

typedef struct history_List
{
	std::string 		input;
	struct history_List	*next;
}				history;

/******************************************************************************\
 * TOOLS
\******************************************************************************/

bool	checkInput(std::string input, std::string field);

/******************************************************************************\
 * CLASS
\******************************************************************************/

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void);
		void	exitPhoneBook(void);

	private:
		Contact		array[MAX_CONTACTS];
		size_t		head;
		int			contactAmount;
		void		showContactList(void);
		void		showContact(size_t choice);
};

#endif