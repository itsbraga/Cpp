/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/23 16:27:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Form::Form(const std::string& name) : _name(name), _isSigned(false), _gradeToSign(42),
									  _gradeToExec(102)
{
	std::cout << BOLD PURPLE "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PURPLE "]" RESET << PURPLE " created" RESET << std::endl;
}

Form::Form(const Form& toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign),
								 _gradeToExec(toCopy._gradeToExec)
{
	std::cout << BOLD PINK "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PINK "]" RESET << PINK " copy created" RESET << std::endl;
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
			  << BOLD PO "]" RESET << PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " is ";
	if (form.getSignatureState() == false)
		os << PO "not signed yet" RESET ".\n";
	else
		os << PG "signed" RESET ".\n";
	os << "To execute it, Bureaucrat must have at least grade "
	   << form.getRequiredGradeToExec() << ".\n" << "To sign it, Bureaucrat "
	   << "must have at least grade " << form.getRequiredGradeToSign() << ".\n";
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

const unsigned int&		Form::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const unsigned int&		Form::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		Form::GradeTooHighException::what() const throw()
{
	return (BOLD RED "Error: " RESET "Grade too high!");
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return (BOLD RED "Error: " RESET "Grade too low!");
}

const char*		Form::AlreadySignedException::what() const throw()
{
	return (BOLD RED "Error: " RESET "Form is already signed!");
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
