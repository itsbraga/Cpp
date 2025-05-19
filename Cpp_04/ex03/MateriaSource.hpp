/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:44:45 by panther           #+#    #+#             */
/*   Updated: 2025/05/19 15:27:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define MAX_ITEMS 4

/******************************************************************************\
 * CLASS
\******************************************************************************/

class MateriaSource : public IMateriaSource
{
	private:
			AMateria*	_inventory[MAX_ITEMS];

	public:
			MateriaSource();
			MateriaSource(const MateriaSource& toCopy);
			MateriaSource&		operator=(const MateriaSource& toCopy);
			virtual ~MateriaSource();

			void		learnMateria(AMateria* m);
			AMateria*	createMateria(std::string const& type);
};

#endif