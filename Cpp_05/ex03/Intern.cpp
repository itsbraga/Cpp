/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:07:15 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/26 22:12:28 by annabrag         ###   ########.fr       */
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
	std::cout << BOLD PY "[Intern]" RESET PY " copy created" RESET << std::endl;
}

Intern&	Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << BOLD PO "[Intern]" RESET PO " destroyed" RESET << std::endl;
}

/*
	------------------------- [ Main function ] --------------------------
*/
AForm*	Intern::makeForm(std::string& form, std::string& target)
{
	std::cout << "Intern creates " << BOLD PINK << form << RESET << std::endl;
}
