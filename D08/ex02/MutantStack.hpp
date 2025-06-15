/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:43:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/16 00:35:32 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <stack>
# include <deque>	// underlying container
# include "../colors.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

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
			iterator				begin();
			iterator				end();
			const_iterator			begin() const;
			const_iterator			end() const;
			reverse_iterator		rbegin();
			reverse_iterator		rend();
			const_reverse_iterator	rbegin() const;
			const_reverse_iterator	rend() const;
};

#endif