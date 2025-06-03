/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:25:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

static std::string	__getDisplayName(const std::string& name)
{
	size_t pos = name.find(" form");
	if (pos != std::string::npos)
		return (name.substr(0, pos));
	return (name);
}

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
AForm::AForm(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << BOLD PURPLE "[Form " UNDERLINE << __getDisplayName(this->_name) << RESET
			  << BOLD PURPLE "]" RESET PURPLE " created" RESET << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
								 _gradeToExec(toCopy._gradeToExec)
{
	std::cout << BOLD PP "[Form " UNDERLINE << __getDisplayName(this->_name) << RESET
			  << BOLD PP "]" RESET PP " copy created" RESET << std::endl;
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
	std::cout << ORANGE "[Form " UNDERLINE << __getDisplayName(this->_name) << RESET
			  << ORANGE "]" RESET ORANGE " destroyed" RESET << std::endl;
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
	----------------------------- [ Getters ] ----------------------------
*/
const std::string&	AForm::getName() const
{
	return (this->_name);
}

const bool&		AForm::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		AForm::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		AForm::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		AForm::GradeTooHighException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too high to sign!");
}

const char*		AForm::GradeTooLowException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too low to sign!");
}

const char*		AForm::AlreadySignedException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Form is already signed!");
}

const char*		AForm::NotSignedException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Form is not signed! You must sign it before trying to execute it.");
}

const char*		AForm::CannotExecuteException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too low to execute the form!");
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}
