/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:31:30 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 04:27:12 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Animal
{
	public:

		Animal();
		Animal(const Animal& toCopy);
		Animal&	operator=(const Animal& toCopy);
		virtual ~Animal();

		std::string		getType() const;
		void			makeSound();


	protected:

		std::string		_type;
};

#endif