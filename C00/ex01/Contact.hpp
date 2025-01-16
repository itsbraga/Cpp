/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:33:40 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/16 18:40:25 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define MAX_CONTACTS 8
# define TOP_BANNER "_____________________________________________"
# define BOTTOM_BANNER "---------------------------------------------"

/******************************************************************************\
 * CLASS
\******************************************************************************/

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

#endif