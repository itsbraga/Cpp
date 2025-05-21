/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:32:24 by annabrag         ###   ########.fr       */
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
	private:
			std::string		_name;

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
};

#endif