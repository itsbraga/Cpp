/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:31:30 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 20:14:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

class WrongAnimal
{
	protected:
			std::string		_type;

	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal& toCopy);
			WrongAnimal&	operator=(const WrongAnimal& toCopy);
			virtual ~WrongAnimal();

			const std::string&	getType() const;
			void				makeSound() const;
};

#endif