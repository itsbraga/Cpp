/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:49:34 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 22:32:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "ICharacter.hpp"
# include "../../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class AMateria
{
	protected:
			std::string	_type;

	public:
			AMateria(std::string const& type);
			AMateria(const AMateria& toCopy);
			AMateria&	operator=(const AMateria& toCopy);
			virtual ~AMateria();

			std::string const&	getType() const;
			virtual AMateria*	clone() const = 0;
			virtual void		use(ICharacter& target);
};

#endif
