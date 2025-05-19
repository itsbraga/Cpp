/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:49:34 by panther           #+#    #+#             */
/*   Updated: 2025/05/19 16:24:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"
# define MAX_ITEMS 4

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ICharacter;

class Character : public ICharacter
{
	private:
			std::string		_name;
			unsigned int	_count;
			AMateria*		_inventory[MAX_ITEMS];

	public:
			Character(const std::string& name);
			Character(const Character& toCopy);
			Character&		operator=(const Character& toCopy);
			~Character();

			std::string const&	getName() const;
			void				equip(AMateria* m);
			void				unequip(int idx);
			void				use(int idx, ICharacter& target);
};

#endif
