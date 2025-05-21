/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/21 20:32:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ClapTrap
{
	protected:
			std::string		_name;
			int				_hitPoints;
			int				_energyPoints;
			int				_attackDamage;

	public:
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& toCopy);
			ClapTrap&	operator=(const ClapTrap& toCopy);
			virtual ~ClapTrap();

			const int&		get_hitPoints() const;
			const int&		get_energyPoints() const;

			void			attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
};

#endif