/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/07 22:10:05 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

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

		int		get_hitPoints() const;
		int		get_energyPoints() const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate();

	private:

	
};

#endif