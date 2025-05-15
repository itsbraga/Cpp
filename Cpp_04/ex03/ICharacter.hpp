/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:49:34 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 22:02:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"
# define MAX_ITEMS 4

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ICharacter
{
	private:
			AMateria*	_inventory[MAX_ITEMS];

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
