/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:32:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class FragTrap : virtual public ClapTrap
{
	public:
			FragTrap(std::string name);
			FragTrap(const FragTrap& toCopy);
			FragTrap&	operator=(const FragTrap& toCopy);
			~FragTrap();

			const int&		get_hitPoints() const;
			const int&		get_energyPoints() const;

			void			attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
			void			highFivesGuys();
};

#endif