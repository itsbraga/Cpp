/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:34:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Dog : public Animal
{
	private:
			Brain*	_Brain;

	public:
			Dog();
			Dog(const Dog& toCopy);
			Dog&	operator=(const Dog& toCopy);
			~Dog();

			const std::string&	getType() const;
			Brain*				getBrain() const;

			void				makeSound() const;
};

#endif