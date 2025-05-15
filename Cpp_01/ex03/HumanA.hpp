/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:34:28 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 20:05:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iostream>
# include "../../colors.hpp"
# include "Weapon.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class HumanA
{
	private:
			std::string	_name;
			Weapon		&_weapon;

	public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA();

			void	attack();
};

#endif