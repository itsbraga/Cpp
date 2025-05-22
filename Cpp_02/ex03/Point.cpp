/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:49:10 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/22 19:29:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	------------------------- [ Canonical form ] -------------------------
*/
Point::Point() : _x(0), _y(0)
{
	// std::cout << BOLD PG "[Default constructor] " RESET << "called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << BOLD PB "[Const float constructor] " RESET << "called" << std::endl;
}

Point::Point(const Point& toCopy) : _x(toCopy._x), _y(toCopy._y)
{
	// std::cout << BOLD PGG "[Copy constructor] " RESET << "called" << std::endl;
}

Point&	Point::operator=(const Point& toCopy)
{
	(void)toCopy;
	// std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	return (*this);
}

Point::~Point()
{
	// std::cout << BOLD RED "[Destructor] " RESET << "called" << std::endl;
}

/*
	---------------------------- [ Getters ] -----------------------------
*/
const Fixed&	Point::getX() const
{
	return (this->_x);
}

const Fixed&	Point::getY() const
{		
	return (this->_y);
}
