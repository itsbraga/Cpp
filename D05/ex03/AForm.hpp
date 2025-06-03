/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:20:24 by annabrag         ###   ########.fr       */
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
	private:
			std::string		_name;
			bool			_isSigned;
			uint32_t		_gradeToSign;
			uint32_t		_gradeToExec;

	public:
			AForm(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec);
			AForm(const AForm& toCopy);
			AForm&		operator=(const AForm& toCopy);
			virtual ~AForm();

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

			class NotSignedException : public std::exception
			{
				const char*		what() const throw();
			};

			class CannotExecuteException : public std::exception
			{
				const char*		what() const throw();
			};

			void			beSigned(const Bureaucrat& bureaucrat);
			virtual void	execute(Bureaucrat const& executor) const = 0;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif