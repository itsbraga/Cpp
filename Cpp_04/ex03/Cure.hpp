/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:26:24 by panther           #+#    #+#             */
/*   Updated: 2025/05/19 16:26:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ICharacter;

class Cure : public AMateria
{
	public:
			Cure();
			Cure(const Cure& toCopy);
			Cure&	operator=(const Cure& toCopy);
			~Cure();

			AMateria*	clone() const;
			void		use(ICharacter& target);
};

#endif