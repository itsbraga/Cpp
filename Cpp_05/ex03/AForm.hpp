/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/26 22:04:41 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

typedef unsigned int uint32_t;

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <fstream>
# include <cstdlib>
# include <ctime>

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class AForm
{
	protected:
			std::string		_name;
			bool			_isSigned;
			uint32_t		_gradeToSign;
			uint32_t		_gradeToExec;

	public:
			AForm(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec);
			AForm(const AForm& toCopy);
			AForm&		operator=(const AForm& toCopy);
			~AForm();

			virtual const std::string&	getName() const = 0;
			virtual const bool&			getSignatureState() const = 0;
			virtual const uint32_t&		getRequiredGradeToSign() const = 0;
			virtual const uint32_t&		getRequiredGradeToExec() const = 0;

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

			class NotSignedException : public std::exception
			{
				const char*		what() const throw();
			};

			class CannotExecuteException : public std::exception
			{
				const char*		what() const throw();
			};

			virtual void	beSigned(const Bureaucrat& bureaucrat) = 0;
			virtual void	execute(Bureaucrat const& executor) const = 0;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif