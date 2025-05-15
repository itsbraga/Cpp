/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:43:57 by panther           #+#    #+#             */
/*   Updated: 2025/05/15 20:20:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class WrongCat : public WrongAnimal
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