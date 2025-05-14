/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:02:01 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& toCopy);
		DiamondTrap&	operator=(const DiamondTrap& toCopy);
		~DiamondTrap();

		const int&		get_hitPoints() const;
		const int&		get_energyPoints() const;
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			whoAmI();

	
	private:

		std::string		_name;
};

#endif