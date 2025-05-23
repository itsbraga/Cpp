/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:14:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/23 15:07:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Form;

class Bureaucrat
{
	private:
			const std::string	_name;
			unsigned int		_grade;

	public:
			Bureaucrat(const std::string& name, unsigned int grade);
			Bureaucrat(const Bureaucrat& toCopy);
			Bureaucrat&		operator=(const Bureaucrat& toCopy);
			~Bureaucrat();

			void					setGrade(unsigned int grade);
			const std::string&		getName() const;
			const unsigned int&		getGrade() const;
			
			class GradeTooHighException : public std::exception
			{
				const char*		what() const throw();
			};
			
			class GradeTooLowException : public std::exception
			{
				const char*		what() const throw();
			};
			
			void		getPromoted();
			void		getDemoted();
			void		signForm(Form& form);
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif