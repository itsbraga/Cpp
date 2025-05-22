/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/22 22:54:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	std::cout << BOLD HOT_PINK "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD HOT_PINK "]" RESET << HOT_PINK " created" RESET << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << BOLD PINK "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD PINK "]" RESET << PINK " copy created" RESET << std::endl;
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	if (this != &toCopy)
		this->_grade = toCopy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD PO "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD PO "]" RESET << PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

/*
	------------------------- [ Setter & Getter ] ------------------------
*/
void	Bureaucrat::setGrade(unsigned int grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

const std::string&		Bureaucrat::getName() const
{
	return (this->_name);
}

const unsigned int&		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD RED "Error: " RESET "Grade too high!");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD RED "Error: " RESET "Grade too low!");
}

/*
	--------------------- [ Increment & Decrement ] ----------------------
*/
void	Bureaucrat::getPromoted()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::getDemoted()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getSignatureState() == false)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because its grade is not high enough... The required"
				  << " grade to sign it is " << form.getRequiredGradeToSign() << std::endl;
	}
	else
		throw Form::AlreadySignedException();
	form.beSigned(*this);
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}
