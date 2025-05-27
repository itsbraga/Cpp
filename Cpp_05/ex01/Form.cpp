/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/27 22:06:45 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Form::Form(const std::string& name, const uint32_t gradeToSign, const uint32_t gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << BOLD PURPLE "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PURPLE "]" RESET PURPLE " created" RESET << std::endl;
}

Form::Form(const Form& toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
								 _gradeToExec(toCopy._gradeToExec)
{
	std::cout << BOLD PP "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PP "]" RESET PP " copy created" RESET << std::endl;
	this->_isSigned = toCopy._isSigned;
}

Form&		Form::operator=(const Form& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	if (this != &toCopy)
		this->_isSigned = toCopy._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << BOLD PO "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PO "]" RESET PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const Form& form)
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
const std::string&		Form::getName() const
{
	return (this->_name);
}

const bool&		Form::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		Form::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		Form::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		Form::GradeTooHighException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too high!");
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too low!");
}

const char*		Form::AlreadySignedException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Form is already signed!");
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}
