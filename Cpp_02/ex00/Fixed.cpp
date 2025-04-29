/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/29 01:05:00 by art3mis          ###   ########.fr       */
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

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		this->_nbr = toCopy._nbr;
	std::cout << BOLD PY "[Copy assignment operator] " RESET << "called"
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
	std::cout << BOLD ORANGE "[getRawBits member function] " RESET << "called"
			  << std::endl;
	return (this->_nbr);
}
