/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/28 01:08:05 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Bureaucrat::Bureaucrat(const std::string& name, uint32_t grade) : _name(name), _grade(grade)
{
	std::cout << BOLD BLUE "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD BLUE "]" RESET BLUE " created" RESET << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << BOLD PB "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD PB "]" RESET PB " copy created" RESET << std::endl;
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
	std::cout << BOLD RED "[Bureaucrat " UNDERLINE << this->_name << RESET
			  << BOLD RED "]" RESET RED " destroyed" RESET << std::endl;
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
void	Bureaucrat::setGrade(uint32_t grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

const std::string&		Bureaucrat::getName() const
{
	return (this->_name);
}

const uint32_t&		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too high!");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("an exception occured.\n" BOLD RED "Error: " RESET "Grade too low!");
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

/*
	------------------------- [ Form function ] --------------------------
*/
void	Bureaucrat::signForm(AForm& form)
{
	if (form.getSignatureState() == true)
		throw AForm::AlreadySignedException();
	try
	{
		form.beSigned(*this);
		std::cout << BOLD << this->_name << RESET " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << BOLD << this->_name << RESET " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD BLUE << this->_name << RESET " couldn't execute " << form.getName()
				  << " because " << e.what() << RESET << std::endl;
	}
}