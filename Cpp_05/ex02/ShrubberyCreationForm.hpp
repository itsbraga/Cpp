/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 22:05:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

typedef unsigned int uint32_t;

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
			ShrubberyCreationForm(const std::string& name);
			ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
			ShrubberyCreationForm&		operator=(const ShrubberyCreationForm& toCopy);
			~ShrubberyCreationForm();

			const std::string&	getName() const;
			const bool&			getSignatureState() const;
			const uint32_t&		getRequiredGradeToSign() const;
			const uint32_t&		getRequiredGradeToExec() const;

			class GradeTooHighException : public std::exception
			{
				const char*		what() const throw();
			};
			
			class GradeTooLowException : public std::exception
			{
				const char*		what() const throw();
			};

			class AlreadySignedException : public std::exception
			{
				const char*		what() const throw();
			};

			virtual void	beSigned(const Bureaucrat& bureaucrat) = 0;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif