/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:21:26 by panther           #+#    #+#             */
/*   Updated: 2025/04/24 00:44:13 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << BOLD PY "[ DEBUG ]" RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
			  << "pickle-special- ketchup burger. I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << BOLD PB "[ INFO ]" RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, "
			  << "I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << BOLD ORANGE "[ WARNING ]" RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working "
			  << "here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << BOLD RED "[ ERROR ]" RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager"
			  << " now.\n";
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[])() = {&Harl::debug, &Harl::info,
											&Harl::warning, &Harl::error};
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
