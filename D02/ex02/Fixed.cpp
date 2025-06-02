/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:47:57 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/26 20:38:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	------------------------- [ Canonical form ] -------------------------
*/
Fixed::Fixed() : _nbr(0)
{
	// std::cout << BOLD PG "[Default constructor] " RESET << "called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	// std::cout << BOLD PGG "[Copy constructor] " RESET << "called" << std::endl;
	*this = toCopy;
}

Fixed::Fixed(const int nbr)
{
	// std::cout << BOLD BLUE "[Int constructor] " RESET << "called" << std::endl;
	if (nbr <= -8388607 || nbr >= 8388607)
		throw std::invalid_argument("int is out of range");
	Fixed::setRawBits(nbr * (1 << _fracBits));
}

Fixed::Fixed(const float nbr)
{
	// std::cout << BOLD PINK "[Float constructor] " RESET << "called" << std::endl;
	if (nbr <= -8388607.1 || nbr >= 8388607.1)
		throw std::invalid_argument("float is out of range");
	Fixed::setRawBits(static_cast<int>(roundf(nbr * (1 << _fracBits))));
}

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	// std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	if (this != &toCopy)
		this->_nbr = toCopy.getRawBits();
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

	result = static_cast<float>(this->_nbr) / (1 << _fracBits);
	return (result);
}

int		Fixed::toInt() const
{
	int	result;

	result = this->_nbr / (1 << _fracBits);
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
	result.setRawBits(tmp / (1 << _fracBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	tmp;

	if (other.getRawBits() == 0)
		throw std::invalid_argument("Zero division is invalid");
	tmp = this->_nbr / other._nbr;
	result.setRawBits(tmp / (1 << _fracBits));
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
