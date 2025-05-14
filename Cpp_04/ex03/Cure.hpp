/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:26:24 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:51:42 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Cure : public AMateria
{
	public:

		Cure(std::string const& type);
		Cure(const Cure& toCopy);
		Cure&	operator=(const Cure& toCopy);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif