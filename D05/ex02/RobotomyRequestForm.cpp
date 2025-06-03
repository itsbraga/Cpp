/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:23:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("Robotomy Request form", 72, 45), _target(target)
{
	std::cout << BOLD HOT_PINK "[" << this->getName() << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->getName() << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (this != &toCopy)
	{
		AForm::operator=(toCopy);
		this->_target = toCopy._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD PO "[" << this->getName() << "]" RESET PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form)
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
void	RobotomyRequestForm::robotomy(const std::string& target) const
{
	std::cout << ITAL LIGHT_GRAY2 "* DRILLING NOISES * Bzzzz..." RESET << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (std::rand() % 2 == 0)
		std::cout << BOLD BLUE << target << RESET " has been robotomized successfully " << std::endl;
	else
		std::cout << BOLD RED "Error: " RESET << "Robotomy failed" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getSignatureState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeToExec())
		throw AForm::CannotExecuteException();
	robotomy(this->_target);
}