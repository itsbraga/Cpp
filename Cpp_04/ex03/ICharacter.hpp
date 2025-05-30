/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:49:34 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 21:44:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "AMateria.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ICharacter
{
	public:
			ICharacter();
			ICharacter(const ICharacter& toCopy);
			ICharacter&		operator=(const ICharacter& toCopy);
			virtual ~ICharacter();

			virtual std::string const&	getName() const = 0;
			virtual void				equip(AMateria* m) = 0;
			virtual void				unequip(int idx) = 0;
			virtual void				use(int idx, ICharacter& target) = 0;
};

#endif
