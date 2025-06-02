/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:21:26 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 19:14:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	// std::cout << BOLD PG "[Constructor] " RESET << "called" << std::endl;
}

Harl::~Harl()
{
	// std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
}

void	Harl::_debug()
{
	std::cout << BOLD PY "[ DEBUG ]" RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
			  << "pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info()
{
	std::cout << BOLD PB "[ INFO ]" RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, "
			  << "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning()
{
	std::cout << BOLD ORANGE "[ WARNING ]" RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << BOLD RED "[ ERROR ]" RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	showMenu()
{
	std::cout << BOLD PP CMD_HEADER << EMPTY_LINE
	
			  << FRONT BOLD PY "\"DEBUG\" level: " RESET
			  << "Debug messages contain contextual information." BOLD PP BACK1
			  << FRONT RESET "\t\t They are mostly used for problem "
			  << "diagnosis." BOLD PP BACK2 << EMPTY_LINE

			  << FRONT PY "\"INFO\" level: " RESET
			  << "These messages contain extensive information." BOLD PP BACK3
			  << FRONT RESET "\t\tThey are helpful for tracing program" BOLD PP BACK4
			  << FRONT RESET "\t\texecution in a production environment." BOLD PP BACK4 << EMPTY_LINE

			  << FRONT BOLD PY "\"WARNING\" level: " RESET
			  << "Warning messages indicate a potential issue" BOLD PP BACK6
			  << FRONT RESET "\t\t   in the system. However, it can be handled" BOLD PP BACK7
			  << FRONT RESET "\t\t   or ignored." BOLD PP BACK8 << EMPTY_LINE

			  << FRONT BOLD PY "\"ERROR\" level: " RESET
			  << "These messages indicate that an unrecoverable" BOLD PP BACK9
			  << FRONT RESET "\t\t error has occurred. This is usually a critical" BOLD PP BACK10
			  << FRONT RESET "\t\t issue that requires manual intervention." BOLD PP BACK11 << EMPTY_LINE
			  << CMD_BOTTOM RESET << std::endl;
}
