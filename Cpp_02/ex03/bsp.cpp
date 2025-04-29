/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:49:54 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/29 01:54:00 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	__sign(Point const& point, Point const& v1, Point const& v2)
{
	// Vecteur v1v2 = v2 - v1
	Fixed	v1v2_x = v2.getX() - v1.getX();
	Fixed	v1v2_y = v2.getY() - v1.getY();

	// Vecteur v1p = p - v1
	Fixed	v1p_x = point.getX() - v1.getX();
	Fixed	v1p_y = point.getY() - v1.getY();

	// Calcul du déterminant (produit vectoriel en 2D)
	// Si > 0 : p est à gauche de v1v2
	// Si < 0 : p est à droite de v1v2
	// Si == 0 : p est sur la droite v1v2
	Fixed	det = v1v2_x * v1p_y - v1v2_y * v1p_x;

	return (det);
}

/*
	BSP (Binary Space Partitioning) is a method used to divide a space
	into smaller regions, which is used to determine if a point is inside
	a polygon by checking if it's on the same side of all the edges of
	the polygon.
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = __sign(point, a, b);
	Fixed	d2 = __sign(point, b, c);
	Fixed	d3 = __sign(point, c, a);

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);

	if ((d1 > Fixed(0) && d2 > Fixed(0) && d3 > Fixed(0)) ||
	    (d1 < Fixed(0) && d2 < Fixed(0) && d3 < Fixed(0)))
		return (true);

	return (false);
}
