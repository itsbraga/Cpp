/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/11 05:25:40 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	------------------------- [ Canonical form ] -------------------------
*/
Fixed::Fixed() : _nbr(0)
{
	std::cout << BOLD PG "[Default constructor] " RESET << "called"
			  << std::endl;
}

Fixed::Fixed(const Fixed& toCopy) : _nbr(toCopy._nbr)
{
	std::cout << BOLD PGG "[Copy constructor] " RESET << "called"
			  << std::endl;
}

Fixed::Fixed(const int nbr)
{
	Fixed::setRawBits(nbr * (1 << _fractionnalBits)); // 256
	std::cout << BOLD BLUE "[Int constructor] " RESET << "called"
			  << std::endl;
}

Fixed::Fixed(const float nbr)
{
	Fixed::setRawBits(roundf(nbr * (1 << _fractionnalBits))); // 256
	std::cout << BOLD PINK "[Float constructor] " RESET << "called"
			  << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		this->_nbr = toCopy._nbr;
	std::cout << BOLD PY "[Assignment operator] " RESET << "called"
			  << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << BOLD RED "[Destructor] " RESET << "called"
			  << std::endl;
}

/*
	------------------------- [ Setter & Getter ] ------------------------
*/
void	Fixed::setRawBits(const int raw)
{
	this->_nbr = raw;
}

int		Fixed::getRawBits() const
{
	return (this->_nbr);
}

/*
	--------------------------- [ Convertion ] ---------------------------
*/
float	Fixed::toFloat() const
{
	float	newValue;

	newValue = static_cast<float>(this->_nbr) / (1 << _fractionnalBits); // 256
	return (newValue);
}

int		Fixed::toInt() const
{
	int	newValue;

	newValue = this->_nbr / (1 << _fractionnalBits); // 256
	return (newValue);
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& RHS)
{
	os << RHS.toFloat();
	return (os);
}
