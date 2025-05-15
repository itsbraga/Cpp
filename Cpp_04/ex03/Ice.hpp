/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:26:24 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 20:22:09 by annabrag         ###   ########.fr       */
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
			Ice();
			Ice(const Ice& toCopy);
			Ice&	operator=(const Ice& toCopy);
			~Ice();

			AMateria*	clone() const;
			void		use(ICharacter& target);
};

#endif