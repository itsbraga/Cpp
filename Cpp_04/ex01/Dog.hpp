/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 17:00:53 by panther          ###   ########.fr       */
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


	private:

		Brain*		_Brain;
};

#endif