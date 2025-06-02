/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:34:28 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 18:50:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CUSTOM
\******************************************************************************/

# define CMD_HEADER "\n=========================  [COMMANDS]  ==========================\n"
# define EMPTY_LINE "|\t\t\t\t\t\t\t\t|\n"
# define FRONT "| "
# define BACK1 " |\n"
# define BACK2 "\t|\n"
# define BACK3 "\t|\n"
# define BACK4 "\t\t|\n"
# define BACK6 "  |\n"
# define BACK7 "\t|\n"
# define BACK8 "\t\t\t\t\t|\n"
# define BACK9 "  |\n"
# define BACK10 " |\n"
# define BACK11 "\t|\n"
# define CMD_BOTTOM "=================================================================\n"

void	showMenu();

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Harl
{
	private:
			void	_debug();
			void	_info();
			void	_warning();
			void	_error();

	public:
			Harl();
			~Harl();

			void	complain(std::string level);
			void	filter(std::string level);
};

#endif