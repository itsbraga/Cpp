/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:07:15 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/28 16:42:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Intern::Intern()
{
	std::cout << BOLD YELLOW "[Intern]" RESET YELLOW " created" RESET << std::endl;
}

Intern::Intern(const Intern& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Intern]" RESET PY " copy created" RESET << std::endl;
}

Intern&		Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << BOLD PO "[Intern]" RESET PO " destroyed" RESET << std::endl;
}

/*
	-------------------------- [ Exceptions ] --------------------------
*/
const char*		Intern::DoesNotExistException::what() const throw()
{
	return (BOLD RED "Error: " RESET "An exception occured. This form does not exist.");
}

/*
	------------------------- [ Main functions ] -------------------------
*/
static AForm*	createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

struct FormEntry
{
	const char	*name;
	AForm*		(*creator)(const std::string&);
};

AForm*	Intern::makeForm(const std::string& form, const std::string& target)
{
	static const FormEntry		forms[] =
	{
		{"Shrubbery creation", createShrubberyForm},
		{"Robotomy request", createRobotomyForm},
		{"Presidential pardon", createPresidentialForm}
	};

	for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); i++)
	{
		if (form == forms[i].name)
		{
			std::cout << "Intern creates " << BOLD PINK << form << RESET " form" << std::endl;
			return (forms[i].creator(target));
		}
	}
	throw DoesNotExistException();
}
