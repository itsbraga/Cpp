/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 17:55:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

typedef unsigned int uint32_t;

# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ClapTrap
{
	private:
			std::string		_name;
			int				_hitPoints;
			int				_energyPoints;
			int				_attackDamage;

	public:
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& toCopy);
			ClapTrap&	operator=(const ClapTrap& toCopy);
			~ClapTrap();

			const int&		get_hitPoints() const;
			const int&		get_energyPoints() const;

			void			attack(const std::string& target);
			void			takeDamage(uint32_t amount);
			void			beRepaired(uint32_t amount);
};

#endif