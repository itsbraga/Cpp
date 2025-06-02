/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 21:20:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

typedef unsigned int uint32_t;

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class Form
{
	private:
			const std::string	_name;
			bool				_isSigned;
			const uint32_t		_gradeToSign;
			const uint32_t		_gradeToExec;

	public:
			Form(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec);
			Form(const Form& toCopy);
			Form&		operator=(const Form& toCopy);
			~Form();

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

			void	beSigned(const Bureaucrat& bureaucrat);
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif