/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:01:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:21:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include "AForm.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
			std::string	_target;

	public:
			PresidentialPardonForm(const std::string& target);
			PresidentialPardonForm(const PresidentialPardonForm& toCopy);
			PresidentialPardonForm&		operator=(const PresidentialPardonForm& toCopy);
			~PresidentialPardonForm();

			void	pardonGranted(const std::string& target) const;
			void	execute(Bureaucrat const& executor) const;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif