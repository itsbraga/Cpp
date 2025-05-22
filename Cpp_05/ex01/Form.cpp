/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/22 18:23:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Form::Form(const std::string& name) : _name(name), _isSigned(false), _gradeToSign(0), _gradeToExec(0)
{
	std::cout << BOLD PURPLE "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PURPLE "]" RESET << PURPLE " created" RESET << std::endl;
}

Form::Form(const Form& toCopy)
{
	std::cout << BOLD PINK "[Form " UNDERLINE << this->_name << RESET
			  << BOLD PINK "]" RESET << PINK " copy created" RESET << std::endl;
	*this = toCopy;
}

Form&		Form::operator=(const Form& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	// 
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
	os << form.getName() << " Form is ";
	if (form.getSignatureState() == false)
		os << "not signed yet "
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
