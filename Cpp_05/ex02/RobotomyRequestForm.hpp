/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/27 19:40:49 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include "AForm.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
			std::string	_target;

	public:
			RobotomyRequestForm(const std::string& target);
			RobotomyRequestForm(const RobotomyRequestForm& toCopy);
			RobotomyRequestForm&		operator=(const RobotomyRequestForm& toCopy);
			~RobotomyRequestForm();

			const std::string&	getName() const;
			const bool&			getSignatureState() const;
			const uint32_t&		getRequiredGradeToSign() const;
			const uint32_t&		getRequiredGradeToExec() const;

			void	beSigned(const Bureaucrat& bureaucrat);
			void	robotomy(const std::string& target) const;
			void	execute(Bureaucrat const& executor) const;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif