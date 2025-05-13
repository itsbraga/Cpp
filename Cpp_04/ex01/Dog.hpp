/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/11 17:00:53 by panther          ###   ########.fr       */
=======
/*   Updated: 2025/05/12 20:38:16 by annabrag         ###   ########.fr       */
>>>>>>> d20ad7bac2f0cf5b0614dd1cccc22f2ce2a6e1a2
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

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

		const std::string	getType() const;
		void				makeSound() const;
		Brain*				getBrain() const;


	private:

		Brain*	_Brain;
};

#endif