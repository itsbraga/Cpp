/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:49:34 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 21:45:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ICharacter;

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
