/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:31:50 by panther           #+#    #+#             */
/*   Updated: 2025/04/28 23:26:01 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iostream>
# include "../../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Zombie
{
	public:

		Zombie();
		~Zombie();

		void				announce();
		void				setName(std::string name);
		const std::string	getName() const;


	private:
	
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
