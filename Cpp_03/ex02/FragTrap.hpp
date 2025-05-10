/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/10 19:09:45 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class FragTrap : public ClapTrap
{
	public:

		FragTrap(std::string name);
		FragTrap(const FragTrap& toCopy);
		FragTrap&	operator=(const FragTrap& toCopy);
		~FragTrap();

		int		get_hitPoints() const;
		int		get_energyPoints() const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys();
};

#endif