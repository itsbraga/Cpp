/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:00:44 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/27 21:26:58 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class AForm;

class Intern
{
	public:
			Intern();
			Intern(const Intern& toCopy);
			Intern&		operator=(const Intern& toCopy);
			~Intern();

			class DoesNotExistException : public std::exception
			{
				const char*		what() const throw();
			};

			AForm*	makeForm(const std::string& form, const std::string& target);
};

#endif