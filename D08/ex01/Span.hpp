/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:43:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/15 22:24:15 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <exception>
# include <cstdlib>
# include <vector>
# include <algorithm>
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

class SpanIsFullException : public std::exception
{
	public:
		virtual const char*		what() const throw()
		{
			return (BOLD RED "Exception caught: " RESET "Span is full");
		}
};

class SpanNotEnoughException : public std::exception
{
	public:
			virtual const char*		what() const throw()
			{
				return (BOLD RED "Exception caught: " RESET "Span has not enough numbers to calculate");
			}
};

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Span
{
	private:
			uint32_t			_N;
			std::vector<int>	_vec;

	public:
			Span( uint32_t N );
			Span( const Span& toCopy );
			Span&	operator=( const Span& toCopy );
			~Span();

			void	addNumber( int number );
			
			template< typename Iterator >
			void	addRange( Iterator first, Iterator last )
			{
				if (this->_vec.size() + std::distance( first, last ) > this->_N)
					throw SpanIsFullException();
				this->_vec.insert( this->_vec.end(), first, last );
			}

			uint32_t	shortestSpan();
			uint32_t	longestSpan();
};

#endif