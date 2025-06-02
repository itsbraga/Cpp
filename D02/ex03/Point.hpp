/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:49:22 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/15 20:10:07 by annabrag         ###   ########.fr       */
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
	private:
			Fixed const	_x;
			Fixed const	_y;

	public:
			Point();
			Point(const float x, const float y);
			Point(const Point& toCopy);
			Point&	operator=(const Point& toCopy);
			~Point();

			const Fixed&	getX() const;
			const Fixed&	getY() const;
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif