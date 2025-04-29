/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/29 01:05:00 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <cmath>
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
		Fixed(const int nbr); 					// const intructor
		Fixed(const float nbr); 				// const floatructor
		Fixed&	operator=(const Fixed& toCopy);	// Copy assignment operator
		~Fixed();

		void	setRawBits(const int raw);
		int		getRawBits() const;
		float	toFloat() const;
		int		toInt() const;


	private:
	
		int					_nbr;
		static const int	_fractionnalBits = 8;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const Fixed& RHS);

#endif