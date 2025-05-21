/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:34:28 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 17:38:47 by annabrag         ###   ########.fr       */
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