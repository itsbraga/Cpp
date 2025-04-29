/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:49:22 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/29 01:13:01 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Point
{
	public:

		Point();
		Point(const float x, const float y);	// Const const floatructor
		Point(const Point& toCopy); 			// Copy constructor
		Point&	operator=(const Point& toCopy);	// Copy assignment operator
		~Point();

		const Fixed&	getX() const;
		const Fixed&	getY() const;


	private:
	
		Fixed const	_x;
		Fixed const	_y;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif