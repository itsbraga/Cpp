/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/10 20:00:46 by panther          ###   ########.fr       */
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

		Fixed(); 								// Default constructor
		Fixed(const Fixed& toCopy); 			// Copy constructor
		Fixed&	operator=(const Fixed& toCopy); // Copy assignment operator
		~Fixed();

		void	setRawBits(const int raw);
		int		getRawBits() const;


	private:
	
		int					_nbr;
		static const int	_fractionnalBits = 8;
};

#endif