/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:31:30 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:34:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class Animal
{
	protected:
			std::string		_type;

	public:
			Animal();
			Animal(const Animal& toCopy);
			Animal&	operator=(const Animal& toCopy);
			virtual ~Animal();

			const std::string&	getType() const;

			virtual void		makeSound() const = 0;
};

#endif