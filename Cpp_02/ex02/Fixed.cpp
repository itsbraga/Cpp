/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/22 17:54:50 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	------------------------- [ Canonical form ] -------------------------

	1 << _fractionnalBits (8) = 256
*/
Fixed::Fixed() : _nbr(0)
{
	// std::cout << BOLD PG "[Default constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	*this = toCopy;
	// std::cout << BOLD PGG "[Copy constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	Fixed::setRawBits(nbr * (1 << _fractionnalBits));
	// std::cout << BOLD BLUE "[Int constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const float nbr)
{
	Fixed::setRawBits(roundf(nbr * (1 << _fractionnalBits)));
	// std::cout << BOLD PINK "[Float constructor] " RESET << "called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		this->_nbr = toCopy.getRawBits();
	// std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
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
	float	result;

	result = static_cast<float>(this->_nbr) / (1 << _fractionnalBits);
	return (result);
}

int		Fixed::toInt() const
{
	int	result;

	result = this->_nbr / (1 << _fractionnalBits);
	return (result);
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& RHS)
{
	os << RHS.toFloat();
	return (os);
}

/*
	---------------------- [ Comparison Operators ] ----------------------
*/
bool	Fixed::operator>(const Fixed& other) const
{
	if (this->_nbr > other._nbr)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->_nbr < other._nbr)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->_nbr >= other._nbr)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->_nbr <= other._nbr)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->_nbr == other._nbr)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->_nbr != other._nbr)
		return (true);
	return (false);
}

/*
	---------------------- [ Arithmetic Operators ] ----------------------
*/
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_nbr + other._nbr);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_nbr - other._nbr);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long	tmp;

	tmp = this->_nbr * other._nbr;
	result.setRawBits(tmp / (1 << _fractionnalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	tmp;

	tmp = this->_nbr / other._nbr;
	result.setRawBits(tmp / (1 << _fractionnalBits));
	return (result);
}

/*
	------------------ [ Increment/Decrement Operators ] -----------------

	Prefix (++a): works directly on the object and returns the new value.
	Postfix (a++): works on a copy in order to return the old value.
*/
Fixed&	Fixed::operator++()
{
	this->_nbr++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_nbr--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

/*
	----------------------------- [ Min/Max ] ----------------------------
*/
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
