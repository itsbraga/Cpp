/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/26 21:52:16 by annabrag         ###   ########.fr       */
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
	std::cout << BOLD HOT_PINK "[" << this->_name << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->_name << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD PO "[" << this->_name << "]" RESET PO " destroyed" RESET << std::endl;
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
	----------------------------- [ Getters ] ----------------------------
*/
const std::string&	RobotomyRequestForm::getName() const
{
	return (this->_name);
}

const bool&		RobotomyRequestForm::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		RobotomyRequestForm::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		RobotomyRequestForm::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	RobotomyRequestForm::robotomy(const Bureaucrat& target) const
{
	std::cout << ITAL LIGHT_GRAY2 "* DRILLING NOISES * Bzzzz..." RESET << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (std::rand() % 2 == 0)
		std::cout << BOLD BLUE << target.getName() << RESET " has been robotomized "
				  << "successfully 50% of the time" << std::endl;
	else
		std::cout << BOLD RED "Error: " RESET << "Robotomy failed" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->_isSigned == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::CannotExecuteException();
	robotomy(executor);
}