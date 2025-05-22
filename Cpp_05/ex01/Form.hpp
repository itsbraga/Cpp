/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/22 22:54:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class Form
{
	private:
			const std::string	_name;
			bool				_isSigned;
			const unsigned int	_gradeToSign;
			const unsigned int	_gradeToExec;

	public:
			Form(const std::string& name);
			Form(const Form& toCopy);
			Form&		operator=(const Form& toCopy);
			~Form();

			const std::string&		getName() const;
			const bool&				getSignatureState() const;
			const unsigned int&		getRequiredGradeToSign() const;
			const unsigned int&		getRequiredGradeToExec() const;

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