/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:20:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("Presidential Pardon form", 25, 5), _target(target)
{
	std::cout << BOLD HOT_PINK "[" << this->getName() << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->getName() << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
	{
		AForm::operator=(toCopy);
		this->_target = toCopy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD PO "[" << this->getName() << "]" RESET PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	if (form.getSignatureState() == false)
		os << form.getName() << " is " PO "not signed yet" RESET ".\n";
	else
		os << form.getName() << " is " PG "signed" RESET ".\n";
	os << "To execute it, Bureaucrat must have at most grade "
	   << form.getRequiredGradeToExec() << ".\n" << "To sign it, Bureaucrat "
	   << "must have at most grade " << form.getRequiredGradeToSign() << ".\n";
	return (os);
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	PresidentialPardonForm::pardonGranted(const std::string& target) const
{
	std::cout << BOLD BLUE << target << RESET " has been pardoned "
			  << "by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSignatureState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeToExec())
		throw AForm::CannotExecuteException();
	pardonGranted(this->_target);
}