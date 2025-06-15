/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 01:09:11 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/15 22:15:53 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

typedef unsigned int uint32_t;

/******************************************************************************\
 * EXCEPTIONS
\******************************************************************************/

class OutOfBoundsException : public std::exception
{
	public:
			virtual const char* what() const throw()
			{
				return (BOLD RED "Exception caught: " RESET "Index out of bounds");
			}
};

/******************************************************************************\
 * TEMPLATE CLASS
\******************************************************************************/

template< typename T >
class Array
{
	private:
			T*			_array;
			uint32_t	_size;

	public:
			Array<T>();
			Array<T>( uint32_t n );
			Array<T>( const Array<T>& toCopy );
			Array<T>&		operator=( const Array<T>& toCopy );
			~Array<T>();

			T&					operator[]( uint32_t index );
			const uint32_t&		size() const { return (this->_size); };
};

#endif