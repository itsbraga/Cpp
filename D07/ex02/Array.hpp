/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 01:09:11 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/02 02:07:11 by art3mis          ###   ########.fr       */
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
 * LIBRARIES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

typedef unsigned int uint32_t;

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
			Array<T>( const Array& toCopy );
			Array<T>&	operator=( const Array& toCopy );
			~Array<T>();

			T&					operator[]( uint32_t index );
			const T&			operator[]( uint32_t index ) const;
			const uint32_t&		size() const;
};

#endif