/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/12 20:31:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Cat : virtual public Animal
{
	public:

		Cat();
		Cat(const Cat& toCopy);
		Cat&	operator=(const Cat& toCopy);
		~Cat();

		std::string		getType() const;
		void			makeSound() const;
		Brain*			getBrain() const;


	private:

		Brain*	_Brain;
};

#endif