/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:43:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/15 23:25:42 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <exception>
# include <stack>
# include <deque>	// underlying container
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

// class MutantStackIsFullException : public std::exception
// {
// 	public:
// 		virtual const char*		what() const throw()
// 		{
// 			return (BOLD RED "Exception caught: " RESET "MutantStack is full");
// 		}
// };

/******************************************************************************\
 * TEMPLATE CLASS
\******************************************************************************/

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
			// Typedefs for iterators
			typedef typename std::stack<T>::container_type::iterator				iterator;
			typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
			typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
			typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

			// Constructors and destructor
			MutantStack<T>();
			MutantStack<T>( const MutantStack<T>& toCopy );
			MutantStack&	operator=( const MutantStack<T>& toCopy );
			~MutantStack();

			// Iterator methods
			iterator				begin() { return this->c.begin(); };
			iterator				end() { return this->c.end(); };
			const_iterator			begin() const { return this->c.begin(); };
			const_iterator			end() const { return this->c.end(); };
			reverse_iterator		rbegin() { return this->c.rbegin(); };
			reverse_iterator		rend() { return this->c.rend(); };
			const_reverse_iterator	rbegin() const { return this->c.rbegin(); };
			const_reverse_iterator	rend() const { return this->c.rend(); };
};

#endif