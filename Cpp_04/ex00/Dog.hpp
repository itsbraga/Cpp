/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:32:46 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Dog : public Animal
{
	public:
			Dog();
			Dog(const Dog& toCopy);
			Dog&	operator=(const Dog& toCopy);
			~Dog();

			const std::string&	getType() const;

			void				makeSound() const;
};

#endif