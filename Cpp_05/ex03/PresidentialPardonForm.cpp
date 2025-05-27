/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/27 20:00:26 by panther          ###   ########.fr       */
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
	std::cout << BOLD HOT_PINK "[" << this->_name << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->_name << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD PO "[" << this->_name << "]" RESET PO " destroyed" RESET << std::endl;
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
	----------------------------- [ Getters ] ----------------------------
*/
const std::string&	PresidentialPardonForm::getName() const
{
	return (this->_name);
}

const bool&		PresidentialPardonForm::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		PresidentialPardonForm::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		PresidentialPardonForm::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	PresidentialPardonForm::pardonGranted(const std::string& target) const
{
	std::cout << BOLD BLUE << target << RESET " has been pardoned "
			  << "by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->_isSigned == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::CannotExecuteException();
	pardonGranted(this->_target);
}