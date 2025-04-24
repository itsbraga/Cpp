/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:14:04 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 15:33:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	// std::cout << BOLD PG "[Constructor] " RESET << "called" << std::endl;
}

Harl::~Harl(void)
{
	// std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << BOLD PY "[ DEBUG ]" RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
			  << "pickle-special- ketchup burger. I really do!"
			  << std::endl;
}

void	Harl::_info(void)
{
	std::cout << BOLD PB "[ INFO ]" RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, "
			  << "I wouldn’t be asking for more!"
			  << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << BOLD ORANGE "[ WARNING ]" RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month."
			  << std::endl;
}

void	Harl::_error(void)
{
	std::cout << BOLD RED "[ ERROR ]" RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[])() = {&Harl::_debug, &Harl::_info,
											&Harl::_warning, &Harl::_error};
	int			i;

	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*functions[i])();
	else
		std::cout << BOLD RED "Error: " RESET << "Invalid level"
				  << std::endl;
}
