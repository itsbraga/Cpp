/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 04:16:34 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Dog : virtual public Animal
{
	public:

		Dog();
		Dog(const Dog& toCopy);
		Dog&	operator=(const Dog& toCopy);
		~Dog();

		std::string		getType() const;
		void			makeSound();
};

#endif