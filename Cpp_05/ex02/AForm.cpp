/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 22:10:42 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
AForm::AForm(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << BOLD PURPLE "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PURPLE "]" RESET << PURPLE " created" RESET << std::endl;
}

AForm::AForm(const AForm& toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
								 _gradeToExec(toCopy._gradeToExec)
{
	std::cout << BOLD PINK "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PINK "]" RESET << PINK " copy created" RESET << std::endl;
	this->_isSigned = toCopy._isSigned;
}

AForm&		AForm::operator=(const AForm& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	if (this != &toCopy)
		this->_isSigned = toCopy._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << BOLD PO "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PO "]" RESET << PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const AForm& form)
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
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		AForm::GradeTooHighException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Grade too high!");
}

const char*		AForm::GradeTooLowException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Grade too low!");
}

const char*		AForm::AlreadySignedException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Form is already signed!");
}
