/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/16 00:38:21 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <exception>
# include "../colors.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * EXCEPTIONS
\******************************************************************************/

class ValueNotFoundException : public std::exception
{
	public:
			virtual const char*		what() const throw()
			{
				return (BOLD RED "Exception caught: " RESET "Value not found in container");
			}
};

/******************************************************************************\
 * TEMPLATE FUNCTIONS
\******************************************************************************/

template< typename T >
typename T::iterator	easyfind( T& container, int value )
{
	typename T::iterator it = std::find( container.begin(), container.end(), value );
	if (it == container.end())
		throw ValueNotFoundException();
	return (it);
}

template< typename T >
typename T::const_iterator	easyfind( const T& container, int value )
{
	typename T::const_iterator it = std::find( container.begin(), container.end(), value );
	if (it == container.end())
		throw ValueNotFoundException();
	return (it);
}

#endif