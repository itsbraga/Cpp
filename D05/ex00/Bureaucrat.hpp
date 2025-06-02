/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:14:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/31 18:50:18 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

typedef unsigned int uint32_t;

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat
{
	private:
			const std::string	_name;
			uint32_t			_grade;

	public:
			Bureaucrat(const std::string& name, uint32_t grade);
			Bureaucrat(const Bureaucrat& toCopy);
			Bureaucrat&		operator=(const Bureaucrat& toCopy);
			~Bureaucrat();

			void					setGrade(uint32_t grade);
			const std::string&		getName() const;
			const uint32_t&			getGrade() const;
			
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
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif