/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:44:45 by panther           #+#    #+#             */
/*   Updated: 2025/05/16 15:34:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

# include "AMateria.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class IMateriaSource
{
	public:
			IMateriaSource();
			IMateriaSource(const IMateriaSource& toCopy);
			IMateriaSource&		operator=(const IMateriaSource& toCopy);
			virtual ~IMateriaSource();

			virtual void		learnMateria(AMateria*) = 0;
			virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif