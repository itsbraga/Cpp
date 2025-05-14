/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 01:04:01 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class WrongCat : virtual public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(const WrongCat& toCopy);
		WrongCat&	operator=(const WrongCat& toCopy);
		~WrongCat();

		const std::string&	getType() const;
		void				makeSound() const;
};

#endif