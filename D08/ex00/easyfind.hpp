/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/06 18:43:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <algorithm>
# include <exception>
# include "../colors.hpp"

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * TEMPLATE FUNCTIONS
\******************************************************************************/

template< typename T >
typename T::iterator	easyfind( T& container, int value )
{
	typename T::iterator it = std::find( container.begin(), container.end(), value );
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return (it);
}

template< typename T >
typename T::const_iterator	easyfind( const T& container, int value )
{
	typename T::const_iterator it = std::find( container.begin(), container.end(), value );
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return (it);
}

#endif