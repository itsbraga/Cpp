/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:26:24 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:40:10 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Ice : public AMateria
{
	public:

		Ice(std::string const& type);
		Ice(const Ice& toCopy);
		Ice&	operator=(const Ice& toCopy);
		~Ice();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif