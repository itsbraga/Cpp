/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:12 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/21 17:38:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <cmath>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Fixed
{
	private:
			int					_nbr;
			static const int	_fractionnalBits = 8;

	public:
			Fixed();
			Fixed(const Fixed& toCopy);
			Fixed&	operator=(const Fixed& toCopy);
			Fixed(const int nbr);
			Fixed(const float nbr);
			~Fixed();

			void		setRawBits(const int raw);
			const int&	getRawBits() const;
			float		toFloat() const;
			int			toInt() const;

			// Comparison operators
			bool	operator>(const Fixed& other) const;
			bool	operator<(const Fixed& other) const;
			bool	operator>=(const Fixed& other) const;
			bool	operator<=(const Fixed& other) const;
			bool	operator==(const Fixed& other) const;
			bool	operator!=(const Fixed& other) const;

			// Arithmetic operators
			Fixed	operator+(const Fixed& other) const;
			Fixed	operator-(const Fixed& other) const;
			Fixed	operator*(const Fixed& other) const;
			Fixed	operator/(const Fixed& other) const;

			// Increment/Decrement operators
			Fixed&	operator++(); 					// Prefix increment
			Fixed	operator++(int); 				// Postfix increment
			Fixed&	operator--(); 					// Prefix decrement
			Fixed	operator--(int); 				// Postfix decrement
			
			static Fixed&		min(Fixed& a, Fixed& b);
			static const Fixed&	min(const Fixed& a, const Fixed& b);
			static Fixed&		max(Fixed& a, Fixed& b);
			static const Fixed&	max(const Fixed& a, const Fixed& b);
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

std::ostream&	operator<<(std::ostream& os, const Fixed& RHS);

#endif