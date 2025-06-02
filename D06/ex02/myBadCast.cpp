/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myBadCast.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:01:04 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/02 19:03:24 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myBadCast.hpp"

myBadCast::myBadCast()
{
}

myBadCast::~myBadCast() throw()
{
}

/*
	-------------------------- [ Exception ] --------------------------
*/
const char*		myBadCast::myBadCast::what() const throw()
{
	return (BOLD RED "Exception caught: " RESET "Bad cast!");
}