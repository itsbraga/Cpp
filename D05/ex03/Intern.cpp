/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:07:15 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:32:49 by annabrag         ###   ########.fr       */
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
static AForm*	__createShrubberyForm(const std::string& target)
{
	try
	{
		return (new ShrubberyCreationForm(target));
	}
	catch (const std::bad_alloc& e)
	{
		throw ;
	}
}

static AForm*	__createRobotomyForm(const std::string& target)
{
	try
	{
		return (new RobotomyRequestForm(target));
	}
	catch (const std::bad_alloc& e)
	{
		throw ;
	}
}

static AForm*	__createPresidentialForm(const std::string& target)
{
	try
	{
		return (new PresidentialPardonForm(target));
	}
	catch (const std::bad_alloc& e)
	{
		throw ;
	}
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
		{"Shrubbery creation", __createShrubberyForm},
		{"Robotomy request", __createRobotomyForm},
		{"Presidential pardon", __createPresidentialForm}
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
