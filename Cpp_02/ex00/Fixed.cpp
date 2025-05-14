/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/14 01:07:26 by panther          ###   ########.fr       */
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

const int&	Fixed::getRawBits() const
{
	std::cout << BOLD ORANGE "[getRawBits member function] " RESET << "called"
			  << std::endl;
	return (this->_nbr);
}
