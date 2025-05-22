/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/22 19:28:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	------------------------- [ Canonical form ] -------------------------
*/
Fixed::Fixed() : _nbr(0)
{
	std::cout << BOLD PG "[Default constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	std::cout << BOLD PGG "[Copy constructor] " RESET << "called" << std::endl;
	*this = toCopy;
}

Fixed::Fixed(const int nbr)
{
	std::cout << BOLD BLUE "[Int constructor] " RESET << "called" << std::endl;
	if (nbr <= -8388607 || nbr >= 8388607)
		throw std::invalid_argument("int is out of range");
	this->setRawBits(nbr * (1 << _fracBits)); // 256
}

Fixed::Fixed(const float nbr)
{
	std::cout << BOLD PINK "[Float constructor] " RESET << "called" << std::endl;
	if (nbr <= -8388607.1 || nbr >= 8388607.1)
		throw std::invalid_argument("float is out of range");
	this->setRawBits(roundf(nbr * (1 << _fracBits))); // 256
}

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	if (this != &toCopy)
		this->_nbr = toCopy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
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
	return (this->_nbr);
}

/*
	--------------------------- [ Convertion ] ---------------------------
*/
float	Fixed::toFloat() const
{
	float	newValue;

	newValue = static_cast<float>(this->_nbr) / (1 << _fracBits); // 256
	return (newValue);
}

int		Fixed::toInt() const
{
	int	newValue;

	newValue = this->_nbr / (1 << _fracBits); // 256
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
