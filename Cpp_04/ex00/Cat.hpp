/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 16:59:28 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

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

		const std::string	getType() const;
		void				makeSound() const;
};

#endif