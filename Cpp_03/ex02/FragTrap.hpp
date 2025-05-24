/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:07 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 17:56:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

typedef unsigned int uint32_t;

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

			const int&		get_hitPoints() const;
			const int&		get_energyPoints() const;

			void			attack(const std::string& target);
			void			takeDamage(uint32_t amount);
			void			beRepaired(uint32_t amount);
			void			highFivesGuys();
};

#endif