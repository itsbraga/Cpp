/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:42:54 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/01 01:45:57 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <iostream>
# include "colors.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void		announce(void);
		void		setName(std::string name);
		std::string	getName(void);


	private:
	
		std::string	name;
};

Zombie  *newZombie(std::string name);
void	randomChump(std::string name);

#endif
