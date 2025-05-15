/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 20:20:32 by annabrag         ###   ########.fr       */
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
	public:

		Dog();
		Dog(const Dog& toCopy);
		Dog&	operator=(const Dog& toCopy);
		~Dog();

		const std::string&	getType() const;
		void				makeSound() const;
		Brain*				getBrain() const;


	private:

		Brain*	_Brain;
};

#endif