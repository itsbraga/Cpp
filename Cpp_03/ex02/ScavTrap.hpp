/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 17:56:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

typedef unsigned int uint32_t;

# include "ClapTrap.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap& toCopy);
			ScavTrap&	operator=(const ScavTrap& toCopy);
			~ScavTrap();

			const int&		get_hitPoints() const;
			const int&		get_energyPoints() const;

			void			attack(const std::string& target);
			void			takeDamage(uint32_t amount);
			void			beRepaired(uint32_t amount);
			void			guardGate();
};

#endif