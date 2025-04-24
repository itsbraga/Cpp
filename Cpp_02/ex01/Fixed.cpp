/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/24 18:49:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _nbr(0)
{
	std::cout << BOLD PG "[Default constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy) : _nbr(toCopy._nbr)
{
	std::cout << BOLD PGG "[Copy constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(int const nbr)
{
	Fixed::setRawBits(nbr * 256);
	std::cout << BOLD BLUE "[Int constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(float const nbr)
{
	Fixed::setRawBits(nbr * 256);
	std::cout << BOLD PINK "[Float constructor] " RESET << "called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		this->_nbr = toCopy._nbr;
	std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->_nbr = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_nbr);
}

float	Fixed::toFloat(void) const
{
	float	newValue;

	newValue = this->_nbr / 256;
	return (newValue);
}

int		Fixed::toInt(void) const
{
	int	newValue;

	newValue = this->_nbr / 256;
	return (newValue);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& RHS)
{
	os << RHS.toFloat();
	return (os);
}
