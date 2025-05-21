/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/21 20:25:33 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << BOLD BLUE "[Bureaucrat " UNDERLINE << this->_name << "]" RESET
			  << BLUE " created" RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
	std::cout << BOLD PB "[Bureaucrat " UNDERLINE << this->_name << "]" RESET
			  << PB " copy created" RESET << std::endl;
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD RED "[Bureaucrat " UNDERLINE << this->_name << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

/*
	------------------------- [ Setter & Getter ] ------------------------
*/
void	Bureaucrat::setGrade(unsigned int grade)
{
	// if (grade < 0 || grade > 150)
	// 	return ;
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
	this->_grade--;
}

void	Bureaucrat::getDemoted()
{
	this->_grade++;
}
