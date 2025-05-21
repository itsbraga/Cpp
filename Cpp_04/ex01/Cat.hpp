/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 20:34:23 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Cat : public Animal
{
	private:
			Brain*	_Brain;

	public:
			Cat();
			Cat(const Cat& toCopy);
			Cat&	operator=(const Cat& toCopy);
			~Cat();

			const std::string&	getType() const;
			Brain*				getBrain() const;

			void				makeSound() const;
};

#endif