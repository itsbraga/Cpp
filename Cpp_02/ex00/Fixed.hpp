/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/24 18:43:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Fixed
{
	public:

		Fixed(void);
		Fixed(const Fixed& toCopy);
		Fixed&	operator=(const Fixed& toCopy);
		~Fixed(void);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;


	private:
	
		int					_nbr;
		static const int	_fracBitsNb = 8;
};

#endif