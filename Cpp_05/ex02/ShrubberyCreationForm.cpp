/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 22:09:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 145, 137)
{
	std::cout << BOLD PURPLE "[" << this->_name << "]" RESET PURPLE " created"
			  << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->_name << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD PO "[" << this->_name << "]" RESET PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form)
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
const std::string&	ShrubberyCreationForm::getName() const
{
	return (this->_name);
}

const bool&		ShrubberyCreationForm::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		ShrubberyCreationForm::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		ShrubberyCreationForm::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Grade too high!");
}

const char*		ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Grade too low!");
}

const char*		ShrubberyCreationForm::AlreadySignedException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. Form is already signed!");
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw ShrubberyCreationForm::GradeTooLowException();
	this->_isSigned = true;
}
